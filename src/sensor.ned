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

package multitargettracking;

//
// Wireless Sensor
//
simple Sensor extends Entity
{
    parameters:
        int id;
        double sleepTime = default(120); // Max sleep time
        double idleTime = default(30); // Idle time before sensor goes to sleep
        double senseInterval = default(1); // Time between sensing frame
        @class(Sensor);
        @display("i=misc/node2;is=vs");

    gates:
        inout senseGate[]; // Connect to targets
        inout gate[]; // Connect to other sensors
}
