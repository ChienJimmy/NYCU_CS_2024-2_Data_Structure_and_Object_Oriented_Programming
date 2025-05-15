#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
vector<tuple<int, char>> MergeSort(vector<tuple<int, char>> &info, int size){
    if(size == 1){
        return info;
    }
    int mid = size / 2;
    vector<tuple<int, char>> left(info.begin(), info.begin() + mid);
    vector<tuple<int, char>> right(info.begin() + mid, info.end());
    
    left = MergeSort(left, mid);
    right = MergeSort(right, size - mid);
    
    vector<tuple<int, char>> merged;
    vector<tuple<int, char>>::iterator p1 = left.begin();
    vector<tuple<int, char>>::iterator p2 = right.begin();
    while (p1 != left.end() && p2 != right.end()){
        if(get<0>(*p1) <= get<0>(*p2)){
            merged.push_back(*p1);
            p1++;
        } else {
            merged.push_back(*p2);
            p2++;
        }
    }
    while (p1 != left.end()){
        merged.push_back(*p1);
        p1++;
    }
    while (p2 != right.end()){
        merged.push_back(*p2);
        p2++;
    }
    return merged;
}
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
    info = MergeSort(info, n);
    for(int i = 0; i < n; i++){
        cout << get<0>(info[i]) << " " << get<1>(info[i]) << "\n";
    }
}