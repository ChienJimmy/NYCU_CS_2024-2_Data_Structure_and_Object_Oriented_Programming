#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    multimap<string, string> ph;
    string command, name, num;
    
    while (cin >> command && command != "exit") {
        cin >> name;
        
        if (command == "add") {
            cin >> num;
            ph.insert({name, num});
        } 
        else if (command == "delete") {
            cin >> num;
            if (num == "ALL") {
                ph.erase(name);
            } else {
                auto range = ph.equal_range(name);
                for (auto it = range.first; it != range.second; ++it) {
                    if (it->second == num) {
                        ph.erase(it);
                        break;
                    }
                }
            }
        }
    }
    
    if (ph.empty()) {
        cout << "empty" << endl;
    } else {
        cout << "phonebook:" << endl;
        string last_name = "";
        for (const auto& entry : ph) {
            if (entry.first != last_name) {
                if (!last_name.empty()) cout << endl;
                cout << entry.first << ":" << endl;
                last_name = entry.first;
            }
            cout << entry.second << endl;
        }
    }
    return 0;
}