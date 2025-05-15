#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<tuple<int, char>> info;
    for(int i = 0; i < n; i++){
        int input_int;
        char input_char;
        cin >> input_int >> input_char;
        info.push_back(make_tuple(input_int, input_char));
    }
    int i = n;
    while (i > 1){
        i--;
        for(int j = 0; j < i; j++){
            if (get<0>(info[j]) > get<0>(info[j + 1])){
                swap(info[j], info[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << get<0>(info[i]) << " " << get<1>(info[i]) << "\n";
    }
}