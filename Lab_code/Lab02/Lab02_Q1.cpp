#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int capacity;
    cin >> capacity;
    list<int> myList(0, -1);
    string command;
    int input(-1), exist(0);
    cin >> command;
    for (;command != "exit";){
        cin >> input;
        if (command == "insert"){
            int num(0);
            exist = 0;
            for (int n : myList) {
                if (n == input){
                    exist = 1;
                }
                num ++;
                if (num == capacity){
                    break;
                }
            }
            //cout << "insert " << exist << "\n";
            if (exist == 0){
                myList.push_front(input);
            }
            else{
                for (list<int>::iterator i = myList.begin(); i != myList.end(); i++){
                    if (*i == input){
                        myList.erase(i);
                        break;
                    }
                }
                myList.push_front(input);
            }
        }
        else if (command == "read"){
            int num(0);
            exist= 0;
            for (int n : myList) {
                if (n == input){
                    exist = 1;
                }
                num ++;
                if (num == capacity){
                    break;
                }
            }
            //cout << "read " << exist << "\n";
            if (exist == 0){
                cout << "key " << input << " is not in LRU\n";
            }
            else{
                for (list<int>::iterator i = myList.begin(); i != myList.end(); i++){
                    if (*i == input){
                        myList.erase(i);
                        break;
                    }
                }
                myList.push_front(input);
            }
        }
        
        cin >> command;
        /*
        for (int n : myList) {
            cout << n << " ";
        }
        cout << "\n";
        */
    }
    list<int>::iterator it, itend;
    it = myList.begin();
    itend =  myList.end();
    int num(0);
    cout << "LRU ";
    for (; it !=  itend; it++, num++){
        cout << *it << " ";
        if (num == capacity - 1){ 
            break;
        }
    }

    return 0;
}