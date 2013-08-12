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

#ifndef __MULTITARGETTRACKING_TARGET_H_
#define __MULTITARGETTRACKING_TARGET_H_

#include <omnetpp.h>
#include "entity.h"

#define MAX_PATH 1000

/**
 * Target to be tracked
 */
class Target : public Entity
{
    private:
        cMessage *moveMsg;
        int *xArr;
        int *yArr;
        int pathLen;
        int posId;
        int loadPath();

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        Target();
        ~Target();
        virtual void updateDisplay();
};

#endif
