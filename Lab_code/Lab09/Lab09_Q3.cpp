#include <iostream>
#include <vector>
using namespace std;
// min-heap
class Heap{
private:
    vector<int> info;

    void heapsort(int i){
        //     parent(i) smaller
        //  l(2i+1)  r(2i+2)
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int size = info.size();
        if (info[smallest] > info[l]){
            if (l < size){
                smallest = l;
            }
        }
        if (info[smallest] > info[r]){
            if (r < size){
                smallest = r;
            }
        }
        if (smallest != i) {
            swap(info[smallest], info[i]);
            heapsort(smallest);
        }
        return;
    }

public:
    void insert(int key){
        if (info.size() == 0) {
            info.push_back(key);
            return;
        }
        info.push_back(key);
        int size = info.size() - 1;
        // swap if parent > child
        int parent = (size - 1) / 2;
        int child = size;
        while (info[parent] > info[child]) {
            swap(info[parent], info[child]);
            child = parent;
            parent = (parent - 1) / 2;
            if (parent < 0){break;}
        }
    }

    int popMin(){
        if (info.size() <= 0){return -100;}
        if (info.size() == 1){
            int root = info[0];
            info.pop_back();
            return root;
        }
        int root = info[0];
        info[0] = info.back();
        info.pop_back();
        heapsort(0);
        return root;
    }

    int getMax(){
        if (info.size() <= 0){return 0;}
        return info[0];
    }

    void remove(int i){
        info[i] = info.back();
        info.pop_back();
        heapsort(i);
    }

    void printHeap(){
        for (int val : info)
            cout << val << " ";
        cout << endl;
    }
    bool empty(){
        return info.size() == 0;
    }
};
int main(){
    int n;
    cin >> n;
    vector<Heap> heaps;
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        Heap heap;
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            heap.insert(val);
        }
        heaps.push_back(heap);
    }
    vector <int> total;
    int element;
    for (int i = 0; i < n; i++){
        while (!heaps[i].empty()){
            element = heaps[i].popMin();
            total.push_back(element);
        }
    }
    for (int i = 0; i < total.size(); i++){
        for (int j = 0; j < total.size() - i - 1; j++){
            if (total[j] > total[j + 1]){
                swap(total[j], total[j + 1]);
            }
        }
    }
    for (int i = 0; i < total.size(); i++){
        cout << total[i] << " ";
    }
}