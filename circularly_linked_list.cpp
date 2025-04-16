#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;

    CNode(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
private:
    CNode* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void append(int val) {
        CNode* newNode = new CNode(val);
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAt(int index, int val) {
        CNode* newNode = new CNode(val);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
            return;
        }
        CNode* temp = tail->next;
        if (index == 0) {
            newNode->next = temp;
            tail->next = newNode;
            return;
        }
        for (int i = 0; i < index - 1 && temp->next != tail->next; i++)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail)
            tail = newNode;
    }

    void deleteVal(int val) {
        if (!tail) return;
        CNode* curr = tail->next;
        CNode* prev = tail;
        do {
            if (curr->data == val) {
                if (curr == tail && curr == tail->next) {
                    delete curr;
                    tail = nullptr;
                } else {
                    prev->next = curr->next;
                    if (curr == tail)
                        tail = prev;
                    if (curr == tail->next)
                        tail->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    bool search(int val) {
        if (!tail) return false;
        CNode* temp = tail->next;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    void display() {
        if (!tail) return;
        CNode* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)\n";
    }
};