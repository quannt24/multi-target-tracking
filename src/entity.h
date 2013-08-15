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

#ifndef __MULTITARGETTRACKING_ENTITY_H_
#define __MULTITARGETTRACKING_ENTITY_H_

#include <omnetpp.h>

/**
 * This class represents an entity in the network. All entities should be subclass of this class.
 */
class Entity : public cSimpleModule
{
    protected:
        int x, y; // Position

        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    public:
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
        // Update display of entity, default behavior is empty
        virtual void updateDisplay();
        // Get distance from current entity to the other
        double distance(Entity *obj);
};

#endif
