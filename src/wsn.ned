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

network Wsn
{
    parameters:
        double width = default(640);
        double height = default(560);
        int numTargets;
        int numSensors;
        int ssRows; // Number of sensor rows
        int ssCols; // Number of sensor columns
        // Note: First ssRows * ssCols sensors will be arranged, the rest is randomly distributed
        @display("bgb=640,560");

    submodules:
        target[numTargets]: Target;
        sensor[numSensors]: Sensor {
            x = intuniform(0, width);
            y = intuniform(0, height);
            @display("p=$x, $y");
        }
        bs: BaseStation;
}
