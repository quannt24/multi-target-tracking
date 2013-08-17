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
#include "target.h"

Define_Module(Sensor);

void Sensor::initialize()
{
    // Initial state is sleeping
    setState(STATE_SLEEP);
    // Plan the first wake up randomly
    scheduleAt(uniform(0, par("sleepTime")), activeMsg);
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
    } else if (msg == senseMsg) {
        startSense();
    } else if (strcmp(msg->getName(), "SensedSignal") == 0){
        recvSenseData(check_and_cast<SensedSignal*>(msg));
    }
}

Sensor::Sensor()
{
    state = STATE_OFF;

    // Create self messages
    // Wake-up timer
    activeMsg = new cMessage("ActiveMsg");
    // 'Go to sleep' timer
    sleepMsg = new cMessage("SleepMsg");
    // Sensing timer
    senseMsg = new cMessage("SenseMsg");
}

Sensor::~Sensor()
{
    cancelAndDelete(activeMsg);
    cancelAndDelete(sleepMsg);
    cancelAndDelete(senseMsg);
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
 * Set state to active and plan a 'go-to-sleep' timer.
 * This function is called only when the sensor wakes up itself, not by a call from other sensors.
 */
void Sensor::activate()
{
    setState(STATE_ACTIVE);
    updateDisplay();
    // Plan for sleeping after idleTime
    // If a working event occurs, cancel this timer and plan new one
    scheduleAt(simTime() + par("idleTime"), sleepMsg);

    // Start sensing immediately
    scheduleAt(simTime(), senseMsg);
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

/*
 * Start a sensing interval. Request targets for sensed data.
 * Cancel and reset sleep timer if event occurs.
 * Set timer for next sensing frame.
 */
void Sensor::startSense()
{
    cModule *wsn = simulation.getModuleByPath("Wsn");
    int numTargets = wsn->par("numTargets");
    int i;
    char tarPath[100]; // Module path for target
    Target *tar;
    double d; // Distance from the sensor to target
    bool hasEvent = false; // Flag to check if an event occurs

    // If the sensor is in range of one target, send request
    for (i = 0; i < numTargets; i++) {
        sprintf(tarPath, "Wsn.target[%d]", i); // Create module path string
        tar = check_and_cast<Target*>(getModuleByPath(tarPath));

        d = this->distance(tar);
        if (d < tar->par("range").doubleValue()) {
            hasEvent = true;
            // Send request
            cMessage *senseMsg = new cMessage("SenseMsg");
            send(senseMsg, "senseGate$o", i); // Gate index and target index are correspondent
        }
    }

    // Cancel and reset sleep timer if event occurs
    if (hasEvent) {
        cancelEvent(sleepMsg);
        scheduleAt(simTime() + par("idleTime"), sleepMsg);
    }

    // Set timer for next sensing frame
    scheduleAt(simTime() + par("senseInterval"), senseMsg);
}

/*
 * Receive signal from a target. This function is called every time a target sends a SensedSignal to the sensor.
 */
void Sensor::recvSenseData(SensedSignal *sig)
{
    EV << "Sensor: got signal";
    delete sig;
}
