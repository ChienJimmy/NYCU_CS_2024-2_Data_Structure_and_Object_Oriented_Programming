#include <iostream>
#include <deque>
using namespace std;
int main(){
    int w, l;
    cin >> w >> l;
    deque<int> info;
    for (int i = 0; i < l; i++){
        int a;
        cin >> a;
        info.push_back(a);
    }
    cout << "Sliding Window Maximums: ";
    for (int i = 0; i < l-w+1; i++){
        int largest = -1000000;
        for (int j = 0; j < w; j++){
            if (info[i+j] > largest){
                largest = info[i+j];
            }
        }
        cout << largest << " ";
    }
    cout << '\n';
}