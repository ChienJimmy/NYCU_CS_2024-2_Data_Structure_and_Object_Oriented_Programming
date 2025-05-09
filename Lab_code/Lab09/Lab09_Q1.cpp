#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, k, input;
    priority_queue<int> pq;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        pq.push(input);
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        cout << pq.top() << " ";
        pq.pop();
    }
}