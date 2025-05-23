#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int capacity;
    cin >> capacity;
    vector<int> hashtables(capacity, 1000);
    string cmd;
    int num, index;
    bool found;
    while((cin >> cmd) && (cmd!= "exit")){
        if (cmd == "Insert"){
            cin >> num;
            index = num % capacity;
            if (hashtables[index] == 1000){
				hashtables[index] = num;
            }
			else {
                while(true){
                    cout << "Collision occurred at index " << index << " for key " << num << "\n";
                    index = (index + 1) % capacity;
                    if (hashtables[index] == 1000){
                        hashtables[index] = num;
                        break;
                    }
                }
            }
        }
        if (cmd == "Search"){
            cin >> num;
            found = false;
            index = num % capacity;
            int times = 0;
            while (true){
                if (times > capacity){
					found = false;
                    break;
                }
                if (hashtables[index] == num){
                    found = true;
                    break;
                }
                index = (num+times) % capacity;
                times++;
            }
            if (found){
                cout << "Search " << num << ": Found\n";
            }
            else{
                cout << "Search " << num << ": Not Found\n";
            }
        }
    }
    for(int i = 0; i < capacity; i++){
        if (hashtables[i] == 1000)
            cout << "Index " << i << ": None\n";
        else{cout << "Index " << i << ": " << hashtables[i] << "\n";}
    }
}