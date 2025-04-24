#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;
    string command;
    int num, a, b;
    
    while (cin >> command && command != "exit") {
        if (command == "insert") {
            cin >> num;
            ms.insert(num);
        } 
        else if (command == "query") {
            cin >> a >> b;
            cout << distance(ms.lower_bound(a), ms.upper_bound(b)) << endl;
        } 
        else if (command == "delete") {
            cin >> num;
            auto it = ms.find(num);
            if (it != ms.end()) {
                ms.erase(it);
            }
        }
    }
    
    for (const auto& val : ms) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}