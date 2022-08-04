#include <iostream>
#include <stack>
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
    
    return 0;
}
