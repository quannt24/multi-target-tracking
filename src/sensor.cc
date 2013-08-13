//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "sensor.h"

Define_Module(Sensor);

void Sensor::initialize()
{
    // Initial state is sleeping
    setState(STATE_SLEEP);
    // Plan the first wake up randomly
    activeMsg = new cMessage("ActiveMsg");
    scheduleAt(uniform(0, par("sleepTime")), activeMsg);
    // Create sleepMsg for 'go to sleep' timer
    sleepMsg = new cMessage("SleepMsg");
}

void Sensor::handleMessage(cMessage *msg)
{
    if (msg == activeMsg) {
        // Self message for waking up sensor when out of sleepTime
        if (state == STATE_ACTIVE) {
            // Check for scheduling error
            EV << "activeMsg timer error (need to be canceled)";
        }
        activate();
    } else if (msg == sleepMsg) {
        // Self message for sensor goes to sleep when out of idleTime
        if (state == STATE_SLEEP) {
            // Check for scheduling error
            EV << "sleepMsg timer error (need to be canceled)";
        }
        gotoSleep();
    }
}

Sensor::Sensor()
{
    state = STATE_OFF;
    activeMsg = NULL; // Prevent error
    sleepMsg = NULL;
}

Sensor::~Sensor()
{
    cancelAndDelete(activeMsg);
    cancelAndDelete(sleepMsg);
}

/*
 * Update display of sensor in simulation
 */
void Sensor::updateDisplay()
{
    cDisplayString &ds = getDisplayString();

    // Update displayed position according to object's coordination (x,y)
    ds.setTagArg("p", 0, x);
    ds.setTagArg("p", 1, y);

    // Set color according to state
    switch (state) {
        case STATE_OFF:
            ds.setTagArg("i", 1, "black");
            break;
        case STATE_SLEEP:
            ds.setTagArg("i", 1, "grey");
            break;
        case STATE_ACTIVE:
            ds.setTagArg("i", 1, "green");
            break;
    }
}

/*
 * Get current state of the sensor
 */
int Sensor::getState()
{
    return state;
}

/*
 * Set working state of the sensor
 */
void Sensor::setState(int state)
{
    if (state == STATE_OFF || state == STATE_SLEEP || state == STATE_ACTIVE) {
        this->state = state;
    }
}

/*
 * Set state to active and plan a 'go-to-sleep' timer
 */
void Sensor::activate()
{
    setState(STATE_ACTIVE);
    updateDisplay();
    // Plan for sleeping after idleTime
    // If a working event occurs, cancel this timer and plan new one
    scheduleAt(simTime() + par("idleTime"), sleepMsg);
}

/*
 * Set state to sleep and plan a wake up timer
 */
void Sensor::gotoSleep()
{
    setState(STATE_SLEEP);
    updateDisplay();
    // Plan for wake up after sleepTime
    // If a working event occurs, wake up immediately and cancel this timer
    scheduleAt(simTime() + par("sleepTime"), activeMsg);
}
