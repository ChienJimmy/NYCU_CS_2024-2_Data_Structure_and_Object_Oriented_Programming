#include <iostream>
using namespace std;
int main(){
    int input;
    cin >> input;
    int f[16] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    for (;input != -1;){
        if (input % 4 == 0){
            int count(1);
            for (int i = 1; i <= input; i++){
                count *= i;
            }
            cout << count << "\n";
        }
        if (input % 4 == 1){
            int fn(1), fn2(0), fn1(0);
            for (int n= 1; n < input; n++){
                fn2 = fn1;
                fn1 = fn;
                fn = fn1 + fn2;
            }
            cout << fn << "\n";
        }
        if (input % 4 == 2){
            cout << -(input * (input +1 )) / 2 << "\n";
        }
        if (input % 4 == 3){
            cout << (input * (input +1 )) / 2 << "\n";
        }
        cin >> input;
    }
}