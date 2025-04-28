#include <stack>
#include <iostream>
using namespace std;
int main(){
    char input;
    stack<int> info;
    while((cin >> input) && input != '\n'){
        if (input == '('){
            info.push(1);
            continue;
        }
        if (input == '['){
            info.push(2);
            continue;
        }
        if (input == '{'){
            info.push(3);
            continue;
        }
        if (input == ')'){
            if(info.empty()){
                cout << "false";
                return 0;
            }
            if(info.top()!=1){
                cout << "false";
                return 0;
            }
            info.pop();
        }
        if (input == ']'){
            if(info.empty()){
                cout << "false";
                return 0;
            }
            if(info.top()!=2){
                cout << "false";
                return 0;
            }
            info.pop();
        }
        if (input == '}'){
            if(info.empty()){
                cout << "false";
                return 0;
            }
            if(info.top()!=3){
                cout << "false";
                return 0;
            }
            info.pop();
        }
    }
    if (info.empty()){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}