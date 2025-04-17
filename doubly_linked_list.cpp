#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val = 0) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    DNode* head; // Sentinel head
    DNode* tail; // Sentinel tail

public:
    DoublyLinkedList() {
        head = new DNode(); // Dummy head
        tail = new DNode(); // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    ~DoublyLinkedList() {
        DNode* current = head;
        while (current) {
            DNode* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(int val) {
        DNode* newNode = new DNode(val);
        DNode* last = tail->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = tail;
        tail->prev = newNode;
    }

    void insertAt(int index, int val) {
        DNode* newNode = new DNode(val);
        DNode* current = head->next;
        for (int i = 0; i < index && current != tail; ++i) {
            current = current->next;
        }
        if (current == nullptr) return;

        DNode* prevNode = current->prev;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = current;
        current->prev = newNode;
    }

    void deleteVal(int val) {
        DNode* current = head->next;
        while (current != tail) {
            if (current->data == val) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
    }

    bool search(int val) {
        DNode* current = head->next;
        while (current != tail) {
            if (current->data == val)
                return true;
            current = current->next;
        }
        return false;
    }

    void displayForward() {
        DNode* current = head->next;
        while (current != tail) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    void displayBackward() {
        DNode* current = tail->prev;
        while (current != head) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL\n";
    }
};