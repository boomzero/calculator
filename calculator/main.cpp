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
    //
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
            else if (be[i]=='/') cs.push(to_string((double)val1/val2));
            else cs.push(to_string(pow(val1, val2)));
            i++;
        }
    }
    cout<<cs.top()<<endl;
    return 0;
}
