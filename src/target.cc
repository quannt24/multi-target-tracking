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
#include <iostream>
#include <fstream>

Define_Module(Target);

void Target::initialize()
{
    // Load path from file
    pathLen = loadPath();
    if (pathLen < 1) {
        EV << "Target: path error";
        return;
    }

    posId = 0;
    setX(xArr[posId]);
    setY(yArr[posId]);
    updateDisplay();

    moveMsg = new cMessage("MoveMsg"); // Self message to move target to new position
    scheduleAt(1.0, moveMsg); // TODO hard code
}

void Target::handleMessage(cMessage *msg)
{
    if (msg == moveMsg && posId < pathLen - 1) {
        // Self message: move
        posId++;
        setX(xArr[posId]);
        setY(yArr[posId]);
        updateDisplay();
        scheduleAt(simTime() + 1.0, msg); // TODO remove hard code
    }
}

Target::Target()
{
    moveMsg = NULL;
    xArr = new int[MAX_PATH];
    yArr = new int[MAX_PATH];
}

Target::~Target()
{
    cancelAndDelete(moveMsg);
    delete xArr;
    delete yArr;
}

// Update display of target in simulation
void Target::updateDisplay()
{
    cDisplayString &ds = getDisplayString();

    // Update displayed position according to object's coordination (x,y)
    ds.setTagArg("p", 0, x);
    ds.setTagArg("p", 1, y);
}

/*
 * Load move path from file.
 * Return number of coordinates read, -1 on error.
 */
int Target::loadPath()
{
    std::ifstream in(par("pathFile"));
    if (!in) {
        EV << "Cannot open path file " << par("pathFile").stringValue() << "\n";
        return -1;
    }

    int n = 0;
    while (!in.eof() && n < MAX_PATH) {
        in >> xArr[n];
        in >> yArr[n];
        n++;
    }

    return n;
}
