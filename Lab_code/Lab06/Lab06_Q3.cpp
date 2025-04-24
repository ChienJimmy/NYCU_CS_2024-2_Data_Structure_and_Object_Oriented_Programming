#include <iostream>
using namespace std;

struct Node {
    //TODO
    int val;
    Node* next;
};

class CircularLinkedList {
public:
    // TODO
    Node* head;
    Node* curr;
    CircularLinkedList() : head(nullptr) {}
    void insert(int value) {
        //TODO
        if(!head) {
            head = new Node{value, head};
            curr = head;
        }
        else {
            Node* newNode = new Node{value, head};
            curr->next = newNode;
            curr = newNode;
        }
    }

    void printNNodesFrom(int startIndex, int n) {
        //TODO
        Node* current = head;
        while(startIndex > 0 && current != nullptr) {
            current = current->next;
            startIndex--;
        }
        while (n > 0) {
            if (current == nullptr) {
                current = head;
            }
            cout << current->val << " ";
            current = current->next;
            n--;
        }
        cout << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    int n, k, startIndex, value;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        cll.insert(value);
    }

    cin >> startIndex;
    cin >> k;
    cll.printNNodesFrom(startIndex, k);

    return 0;
}