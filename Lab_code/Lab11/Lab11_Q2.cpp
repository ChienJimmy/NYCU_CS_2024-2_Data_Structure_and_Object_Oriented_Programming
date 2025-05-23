#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int capacity;
    cin >> capacity;
    vector<vector<int>> hashtables(capacity);
    string cmd;
    int num, index;
    bool found;
    while ((cin >> cmd) && (cmd != "exit")) {
        if (cmd == "Insert") {
            cin >> num;
            index = num % capacity;
            if(hashtables[index].size() != 0) {
                cout << "Collision occurred at index " << index << " for key " << num << "\n";
            }
            hashtables[index].push_back(num);
        }

        if (cmd == "Search") {
            cin >> num;
            found = false;
            index = num % capacity;
            for(int i = 0; i <= capacity; i++) {
                if (hashtables[index][i] == num) {
                    found = true;
                    break;
                }
            }
            if (found){
                cout << "Search " << num << ": Found\n";
            }
            else{
                cout << "Search " << num << ": Not Found\n";
            }
        }
    }
    for (int i = 0; i < capacity; i++) {
        cout << "Index " << i << ": ";
        for (vector<int>::iterator it = hashtables[i].begin(); it != hashtables[i].end(); ++it) {
            cout << *it << " -> ";
        }
        cout << "nullptr\n";
    }
}