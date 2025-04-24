#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> studentMap;
    string command, name;
    int score(0);
    cin >> command;
    while (command != "exit"){
        if (command == "listall"){
            if (studentMap.empty()){
                cout << "The database is empty.\n";
            }
            for (const auto &s : studentMap) {
                cout << s.first << " " << s.second << "\n";
            }
            cin >> command;
            continue;
        }
        cin >> name;
        if (command == "add"){
            cin >> score;
            studentMap[name] = score;
        }
        if (command == "search"){
            int exist(0);
            for (const auto& s : studentMap) {
                if (s.first == name){
                    exist = 1;
                }
            }
            if (exist){
                cout << name << " " << studentMap[name] << "\n"; 
            }
            else {
                cout << "Can't find " << name << "'s data.\n";
            }

        }
        if (command == "delete"){
            int exist(0);
            for (const auto& s : studentMap) {
                if (s.first == name){
                    exist = 1;
                }
            }
            if (exist){
                studentMap.erase(name);
            }
            else {
                cout << "Can't delete " << name << "'s data.\n";
            }
        }


        cin >> command;
    }
    return 0;
}