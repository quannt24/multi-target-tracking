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

#ifndef __MULTITARGETTRACKING_SENSOR_H_
#define __MULTITARGETTRACKING_SENSOR_H_

#include <omnetpp.h>
#include "entity.h"

// Working states
#define STATE_OFF 0 // Turned off or out of energy
#define STATE_SLEEP 1 // Just listen to other nodes
#define STATE_ACTIVE 2 // Sensing and transmit data

/**
 * Wireless Sensor
 */
class Sensor : public Entity
{
    private:
        int state; // Working state
        cMessage *activeMsg; // Self message for waking up sensor when out of sleepTime
        cMessage *sleepMsg; // Self message for sensor goes to sleep when out of idleTime
        cMessage *senseMsg; // Self message for start sensing

        void activate();
        void gotoSleep();
        void startSense();
        void finishSense();

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        Sensor();
        ~Sensor();
        virtual void updateDisplay();
        int getState();
        void setState(int state);
};

#endif
