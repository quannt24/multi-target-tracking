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

#include "basestation.h"
#include "sensor.h"

Define_Module(BaseStation);

void BaseStation::initialize()
{
    // Arrange sensors
    cModule *wsn = simulation.getModuleByPath("Wsn");
    double wsnWidth = wsn->par("width");
    double wsnHeight = wsn->par("height");
    int ssRows = wsn->par("ssRows");
    int ssCols = wsn->par("ssCols");
    int numSensors = wsn->par("numSensors");
    char modPath[100]; // Module path for sensors
    Sensor *ss;

    int i = 0;
    int n = numSensors <= ssRows * ssCols ? numSensors : ssRows * ssCols; // Number of sensors which will be arranged
    for (i = 0; i < n; i++) {
        sprintf(modPath, "Wsn.sensor[%d]", i); // Create module path string
        ss = check_and_cast<Sensor*>(getModuleByPath(modPath));
        ss->setX((i % ssCols) * rint(wsnWidth / ssCols) + intuniform(0, wsnWidth / ssCols / 2));
        ss->setY((i / ssCols) * rint(wsnHeight / ssRows) + intuniform(0, wsnHeight / ssRows / 2));
        ss->updateDisplay();
    }
}

void BaseStation::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}
