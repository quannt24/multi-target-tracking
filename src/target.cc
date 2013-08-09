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

#include "target.h"
#include "entity.h"

Define_Module(Target);

void Target::initialize()
{
    moveMsg = new cMessage("MoveMsg"); // Self message to move target to new position
    scheduleAt(0.0, moveMsg);
}

void Target::handleMessage(cMessage *msg)
{
    if (msg == moveMsg) {
        // Self message: move
        setX(random() % 500);
        setY(random() % 500);
        updateDisplay();
        scheduleAt(simTime() + 1, msg); // TODO remove hard code
    }
}

Target::Target()
{
    moveMsg = NULL;
}

Target::~Target()
{
    cancelAndDelete(moveMsg);
}

void Target::updateDisplay()
{
    cDisplayString &ds = getDisplayString();

    // Update displayed position according to object's coordination (x,y)
    ds.setTagArg("p", 0, x);
    ds.setTagArg("p", 1, y);
}
