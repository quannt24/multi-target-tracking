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
    public:
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);

    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);

    private:
        int x, y; // Position
};

#endif
