#include <queue>
#include <iostream>
using namespace std;
int main(){
    queue<int> q;
    int input;
    while((cin >> input) && input != 0){
        for(int i = 1; i <= input; i++){
            q.push(i);
        }
        cout << "Discarded integers: ";
        while(q.size()!=2){
            cout << q.front() << ", ";
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << "\nRemaining integer: ";
        q.pop();
        cout << q.front() << "\n";
        q.pop();
    }
    return 0;
}