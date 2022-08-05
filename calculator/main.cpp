#include <iostream>
#include <stack>
#include <string>
#include <cmath>
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
        temp="";
        if (isdigit(expression[i])) {//This is a number
            while (isdigit(expression[i])) {
                temp.push_back(expression[i]);
                i++;
            }
            i--;
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
                    while ((!s1.empty())&&!(getPriority(temp)>getPriority(s1.top()))) {
                        s2.push(s1.top());
                        s1.pop();
                    }
                s1.push(temp);
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
        if (s2.size()!=1)
            be.insert(0, " ");
        s2.pop();
    }
    stack<string> cs;
    string temp2;
    long long val1=0,val2=0;
    for (int i=0; i<be.length(); i++) {
        temp2="";
        if (isdigit(be[i])) {
            while (be[i]!=' ') {
                temp2.push_back(be[i]);
                i++;
            }
            cs.push(temp2);
        }else{
            val2=stoi(cs.top());
            cs.pop();
            val1=stoi(cs.top());
            cs.pop();
            if (be[i]=='+') {
                cs.push(to_string(val1+val2));
            }else if (be[i]=='-') cs.push(to_string(val1-val2));
            else if (be[i]=='*') cs.push(to_string(val1*val2));
            else if (be[i]=='/') cs.push(to_string(val1/val2));
            else cs.push(to_string(round(pow(val1, val2))));
            i++;
        }
    }
    cout<<cs.top()<<endl;
    return 0;
}
