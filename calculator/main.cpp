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
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>
#include <iomanip>

using namespace std;

string ldtos(long double val) {
    std::stringstream ss;
    ss << std::setprecision(15) << val;
    return ss.str();
}

int getPriority(const string &op) {
    if (op == "^"||op=="sqrt") {
        return 3;
    } else if (op == "*" || op == "/") {
        return 2;
    } else if (op == "+" || op == "-") {
        return 1;
    }
    return 0;
}

int main() {
    stack<string> s1;
    stack<string> s2;
    string expression;
    cin >> expression;
    if (expression[0] == '-' || expression[0] == '+') {
        expression.insert(0, "0");
    }
    for (int i = 1; i < expression.length(); i++) {
        if ((expression[i] == '-' || expression[0] == '+') && expression[i - 1] == '(') {
            expression.insert(i, "0");
        }
    }
    string temp;
    for (int i = 0; i < expression.length(); i++) {
        temp = "";
        if (isdigit(expression[i])) {
            while (isdigit(expression[i]) || expression[i] == '.') {
                temp.push_back(expression[i]);
                i++;
            }
            i--;
            s2.push(temp);
        } else {
            if (s1.empty() || (s1.top() == "(")) {
                if (!s1.empty() && (expression[i] == ')') && s1.top() == "(") {
                    s1.pop();
                } else {
                    if (expression[i]=='s'&&expression[i+1]=='q'){
                        i+=3;
                        s1.push("r");
                    }else {
                        temp = "";
                        temp.push_back(expression[i]);
                        s1.push(temp);
                    }
                }
            } else {
                temp = "";
                if (expression[i]=='s'&&expression[i+1]=='q'){
                    temp="sqrt";
                }else{
                    temp.push_back(expression[i]);
                }
                if (temp == "(") {
                    s1.push("(");
                } else if (temp == ")") {
                    while (s1.top() != "(") {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s1.pop();
                } else {
                    while ((!s1.empty()) && getPriority(temp) <= getPriority(s1.top())) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    if (temp=="sqrt"){
                        s1.push("s");
                        i+=3;
                    }else {
                        s1.push(temp);
                    }
                }
            }
        }
    }
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    string be;
    while (!s2.empty()) {
        be.insert(0, s2.top());
        if (s2.size() != 1)
            be.insert(0, " ");
        s2.pop();
    }
    bool sn = true;
    for (char i: be) {
        if (!isdigit(i) && i != '.') {
            sn = false;
        }
    }
    if (sn) {
        cout << be << endl;
#ifdef __WIN32
        system("pause");
#endif
        return 0;
    }
    stack<string> cs;
    string temp2;
    long double val1, val2;
    for (int i = 0; i < be.length(); i++) {
        temp2 = "";
        if (isdigit(be[i])) {
            while (be[i] != ' ') {
                temp2.push_back(be[i]);
                i++;
            }
            cs.push(temp2);
        }else if (isalpha(be[i])){
            i++;
        }else {
            val2 = stold(cs.top());
            cs.pop();
            val1 = stold(cs.top());
            cs.pop();
            if (be[i] == '+') cs.push(ldtos(val1 + val2));
            else if (be[i] == '-') cs.push(ldtos(val1 - val2));
            else if (be[i] == '*') cs.push(ldtos(val1 * val2));
            else if (be[i] == '/') cs.push(ldtos((long double) val1 / val2));
            else cs.push(ldtos((long double) pow(val1, val2)));
            i++;
        }
    }
    cout << cs.top() << endl;
#ifdef __WIN32
    system("pause");
#endif
    return 0;
}
