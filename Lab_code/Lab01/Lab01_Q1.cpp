#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int birthyr;
    string name;
    cin >> name;
    for (;name != "-1";){
        cin >> birthyr;
        cout <<"Hello " << name << ". Your age is "  << 2025 - birthyr << ".\n";
        cin >> name;
    }
    
}