/*
This program is free software: you can redistribute it and/or modify it under the terms of
the GNU General Public License as published by the Free Software Foundation, either
version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.
If not, see <https://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;
ifstream fi("ans.txt");

int main() {
    string expr;
    cin >> expr;
    stringstream c;
    c<<"echo $(("<<expr<<")) > ans.txt";
    system(c.str().c_str());
    string cmd = "echo ";
    cmd.append(expr);
    cmd.append("| ./calculator > out.txt");
    system(cmd.c_str());
    return system("diff ans.txt out.txt");
}