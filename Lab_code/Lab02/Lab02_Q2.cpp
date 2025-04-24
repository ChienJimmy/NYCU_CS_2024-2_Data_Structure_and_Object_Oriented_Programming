#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int times, input(1);
    cin >> times;
    for (int i = 0; i < times; i++){
        std::set<int> myset1{}, myset2{}, myset3{}, myset4{}, myset5{};
        cin >> input;
        while (input != -1){
            myset1.insert(input);
            cin >> input;
        }
        cin >> input;
        while (input != -1){
            myset2.insert(input);
            cin >> input;
        }
        
        for (const auto &s : myset1) {
            if (myset2.count(s)){
                myset4.insert(s);
            }
            else {
                myset5.insert(s);
            }
            myset3.insert(s);
        }
        for (const auto &s : myset2) {
            myset3.insert(s);
        }
        cout << "intersection: ";
        if (myset4.empty()){
            cout << "None";
        }
        for (const auto &s : myset4) {
            cout << s << " ";
        }
        cout << "\ndifference: ";
        if (myset5.empty()){
            cout << "None";
        }
        for (const auto &s : myset5) {
            cout << s << " ";
        }
        cout << "\nunionSet: ";
        if (myset3.empty()){
            cout << "None";
        }
        for (const auto &s : myset3) {
            cout << s << " ";
        }
        cout << "\n";

    }
    return 0;
}