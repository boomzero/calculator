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
        if (isdigit(expression[i])) {
            while (isdigit(expression[i])) {
                temp.push_back(expression[i]);
                i++;
            }
            s2.push(temp);
        }
    }
    return 0;
}
