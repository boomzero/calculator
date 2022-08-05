#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int getPriority(string op){
    if (op=="^") {
        return 3;
    }else if (op=="*"||op=="/"){
        return 2;
    }else{
        return 1;
    }
}
int main() {
    stack<string> s1;
    stack<string> s2;
    string expression;
    cin>>expression;
    string temp;
    for (int i=0; i<expression.length(); i++) {
        if (isdigit(expression[i])) {//This is a number
            while (isdigit(expression[i])) {
                temp.push_back(expression[i]);
                i++;
            }
            s2.push(temp);
        }else{//This is an operator
            if (s1.empty()||s1.top()=="(") {
                temp="";
                temp.push_back(expression[i]);
                s1.push(temp);
            }else{
                temp="";
                temp.push_back(expression[i]);
                if (temp==")") {
                    while (s1.top()!="(") {
                        s2.push(s1.top());
                        s1.pop();
                    }
                    s1.pop();
                }else{
                    while (!(getPriority(temp)>getPriority(s1.top()))&&(!s1.empty())) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                s1.push(temp);
                }
            }
        }
    }
    string be;
    while (!s2.empty()) {
        be.insert(0, s2.top());
        s2.pop();
    }
    return 0;
}
