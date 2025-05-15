#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
vector<int> Quicksort(vector<int> &info, int size){
    if (size <= 1){
        return info;
    }
    int pivot  = info[size-1];
    vector<int> left;
    vector<int> right;
    vector<int> e;
    for(int i = 0; i < size; i++){
        if(info[i] < pivot){
            left.push_back(info[i]);
            continue;
        }
        if(info[i] > pivot){
            right.push_back(info[i]);
            continue;
        }
        if (info[i] == pivot){
            e.push_back(info[i]);
            continue;
        }
    }
    vector<int> leftsort, rightsort;
    leftsort = Quicksort(left, left.size());
    rightsort = Quicksort(right, right.size());
    vector<int> ans;
    for(int i = 0; i < leftsort.size(); i++){
        ans.push_back(leftsort[i]);
    }
    for(int i = 0; i < e.size(); i++){
        ans.push_back(e[i]);
    }
    for(int i = 0; i < rightsort.size(); i++){
        ans.push_back(rightsort[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> info;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        info.push_back(input);
    }
    info = Quicksort(info, n);
    for(int i = 0; i < n; i++){
        cout << info[i] <<  " ";
    }
}