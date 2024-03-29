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
//#include <vector>

const long double PI = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
using namespace std;

string toString(long double val) {
    std::stringstream ss;
    ss << std::setprecision(15) << val;
    return ss.str();
}

int getPriority(const string &op) {
    if (op == "^" || op == "sqrt" || op == "s") {
        return 3;
    } else if (op == "*" || op == "/") {
        return 2;
    } else if (op == "+" || op == "-") {
        return 1;
    }
    if (op == "(" || op == ")") {
        return 0;
    }
    string err = "Unknown operator: ";
    err.append(op);
#ifdef __WIN32
    cerr << err << endl;
    system("pause");
#endif
    throw runtime_error(err.c_str());
}

int main() {
    stack<string> s1;
    stack<string> s2;
    string expr;
    getline(cin, expr);
    auto isOp = [](char in) -> bool {
        if (in == '+' || in == '-' || in == '*' || in == '/' || in == '^' || in == 's' || in == 't')
            return true; //you should not just use s for sqrt
        return false;
    };
    while (expr.find(' ') != string::npos) {
        expr.erase(expr.find(' '), 1); //remove spaces
    }
    if (expr[0] == '-' || expr[0] == '+') {
        expr.insert(0, "0"); //allow +n and -n
    }
    for (int i = 1; i < expr.length(); i++) {
        if ((expr[i] == '-' || expr[i] == '+') && expr[i - 1] == '(') {
            expr.insert(i, "0"); //allow (+n) and (-n)
        } else if (expr[i] == '-' && expr[i - 1] == '^') {
            expr.insert(i, "(0"); //allow n^-n
            expr.insert(i + 4, ")");
        } else if (expr[i] == '(' && (/*isOp(expr[i - 1]) ||*/ expr[i - 1] == ')')) {
            expr.insert(i, "*");
        }
    }
    string temp;
    for (int i = 0; i < expr.length(); i++) {
        temp = "";
        if (isdigit(expr[i])) {
            while (isdigit(expr[i]) || expr[i] == '.') {
                temp.push_back(expr[i]);
                i++;
            }
            i--;
            s2.push(temp);
        } else if (expr[i] == 'p' && expr[i + 1] == 'i') {
            i++;
            s2.push(toString(PI));
        } else {
            if (s1.empty() || (s1.top() == "(")) {
                if (!s1.empty() && (expr[i] == ')') && s1.top() == "(") {
                    s1.pop();
                } else {
                    if (expr[i] == 's' && expr[i + 1] == 'q') {
                        i += 3;
                        s1.emplace("s");
                    } else {
                        temp = "";
                        temp.push_back(expr[i]);
                        s1.push(temp);
                    }
                }
            } else {
                temp = "";
                if (expr[i] == 's' && expr[i + 1] == 'q') {
                    temp = "sqrt";
                } else {
                    temp.push_back(expr[i]);
                }
                if (temp == "(") {
                    s1.emplace("(");
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
                    if (temp == "sqrt") {
                        s1.emplace("s");
                        i += 3;
                    } else {
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
    if (be.find('(') != string::npos || be.find(')') != string::npos) {
#ifdef __WIN32
        cerr << "Parentheses do not match!" << endl;
        system("pause");
#endif
        throw runtime_error("Parentheses do not match!");
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
        } else if (isalpha(be[i])) {
            if (cs.empty()) {
#ifdef __WIN32
                cerr << "Invalid input!" << endl;
                system("pause");
#endif
                throw runtime_error("Invalid input!");
            }
            val1 = stold(cs.top());
            cs.pop();
            if (be[i] == 's') {
                cs.push(toString(sqrt(val1)));
            }
            i++;
        } else {
            if (cs.empty()) {
#ifdef __WIN32
                cerr << "Invalid input!" << endl;
                system("pause");
#endif
                throw runtime_error("Invalid input!");
            }
            val2 = stold(cs.top());
            cs.pop();
            if (cs.empty()) {
#ifdef __WIN32
                cerr << "Invalid input!" << endl;
                system("pause");
#endif
                throw runtime_error("Invalid input!");
            }
            val1 = stold(cs.top());
            cs.pop();
            if (be[i] == '+') cs.push(toString(val1 + val2));
            else if (be[i] == '-') cs.push(toString(val1 - val2));
            else if (be[i] == '*') cs.push(toString(val1 * val2));
            else if (be[i] == '/') cs.push(toString(val1 / val2));
            else cs.push(toString(pow(val1, val2)));
            i++;
        }
    }
    cout << cs.top() << endl;
#ifdef __WIN32
    system("pause");
#endif
    return 0;
}
