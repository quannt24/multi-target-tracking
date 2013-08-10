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

#include "entity.h"

Define_Module(Entity);

void Entity::initialize()
{
    // Default behavior is empty
}

void Entity::handleMessage(cMessage *msg)
{
    // Default behavior is empty
}

int Entity::getX()
{
    return x;
}

void Entity::setX(int x)
{
    this->x = x;
}

int Entity::getY()
{
    return y;
}

void Entity::setY(int y)
{
    this->y = y;
}

void Entity::updateDisplay()
{
    // Default behavior is empty
}
