#include <iostream>
#include <string>
// TODO
// You can't use <algorithm>
using namespace std;

class Database {
private:
    struct Record {
        int id;
        string name;
        int age;
    };

    // TODO
    Record list[1000]={};

public:
    // TODO
    void addRecord(int in1, string in2, int in3){
        int inlist(0);
        for (int i = 0; i < 1000; i++){
            if (list[i].id == in1){
                inlist = 1;
            }
        }
        if (inlist){
            cout << "Can't add this ID.\nID " << in1 << " already exists.\n";
        }
        else {
            for (int i = 0; i < 1000; i++){
                if (list[i].id == 0 && list[i].id != -1){
                    list[i].id = in1;
                    list[i].name = in2;
                    list[i].age = in3;
                    break;
                }

            }
        }
    }
    void printAllRecords(){
        cout << "All records:\n";
        for (int i = 0; i < 1000; i++){
            if (list[i].id != 0){
                cout << "ID: " << list[i].id << ", Name: " << list[i].name << ", Age: " << list[i].age << "\n";
            }
        }
    }
    void deleteRecord(int in1){
        int inlist(0);
        for (int i = 0; i < 1000; i++){
            if (list[i].id == in1){
                inlist = 1;
            }
        }
        if (inlist){
            for (int i = 0; i < 1000; i++){
                if (list[i].id == in1){
                    list[i].id = 0;
                    list[i].name = "";
                    list[i].age = -1;
                }
            }         
        }
        else {
            cout << "Can't delete this ID.\nID " << in1 << " does not exist.\n";
        }
    }
    void findRecord(int in1){
        int inlist(0);
        for (int i = 0; i < 1000; i++){
            if (list[i].id == in1){
                inlist = 1;
            }
        }
        if (inlist){
            for (int i = 0; i < 1000; i++){
                if (list[i].id == in1){
                    cout << "ID: " << list[i].id << ", Name: " << list[i].name << ", Age: " << list[i].age << "\n";
                }
            }         
        }
        else {
            cout << "Can't find this ID.\nID " << in1 << " does not exist.\n";
        }
    }
    void findRecord(string in1){
        int inlist(0);
        for (int i = 0; i < 1000; i++){
            if (list[i].name == in1){
                inlist = 1;
            }
        }
        if (inlist){
            for (int i = 0; i < 1000; i++){
                if (list[i].name == in1){
                    cout << "ID: " << list[i].id << ", Name: " << list[i].name << ", Age: " << list[i].age << "\n";
                    break;
                }
            }         
        }
        else {
            cout << "Can't find this name.\nName " << in1 << " does not exist.\n";
        }
    }
};

int main() {
    Database db;

    db.addRecord(1, "Alice", 20);
    db.addRecord(2, "Bob", 22);
    db.addRecord(3, "Charlie", 19);
    db.addRecord(2, "Duplicate Bob", 25);
    // Can't add this ID.
    // ID 2 already exists.
    db.printAllRecords();
    // All records:
    // ID: 1, Name: Alice, Age: 20
    // ID: 2, Name: Bob, Age: 22
    // ID: 3, Name: Charlie, Age: 19

    db.deleteRecord(2);
    db.deleteRecord(2);
    // Can't delete this ID.
    // ID 2 does not exist. 
    db.printAllRecords();
    // All records:
    // ID: 1, Name: Alice, Age: 20
    // ID: 3, Name: Charlie, Age: 19

    db.findRecord(1);
    // ID: 1, Name: Alice, Age: 20
    db.findRecord(2);
    // Can't find this ID.
    // ID 2 does not exist.
    db.findRecord("Alice");
    // ID: 1, Name: Alice, Age: 20
    db.findRecord("Bob");
    // Can't find this name.
    // Name Bob does not exist.

    return 0;
}