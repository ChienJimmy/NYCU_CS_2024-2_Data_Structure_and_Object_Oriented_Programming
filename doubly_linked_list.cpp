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

    void addFront(int val) {
        DNode* newNode = new DNode(val);
        DNode* first = head->next;

        newNode->next = first;
        newNode->prev = head;
        head->next = newNode;
        first->prev = newNode;
    }

    void addBack(int val) {
        DNode* newNode = new DNode(val);
        DNode* last = tail->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = tail;
        tail->prev = newNode;
    }

    void removeFront() {
        if (head->next == tail) return; // List is empty
        DNode* first = head->next;
        head->next = first->next;
        first->next->prev = head;
        delete first;
    }

    void removeBack() {
        if (tail->prev == head) return; // List is empty
        DNode* last = tail->prev;
        tail->prev = last->prev;
        last->prev->next = tail;
        delete last;
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

    void reverse() {
        DNode* current = head;
        while (current != nullptr) {
            swap(current->next, current->prev);
            current = current->prev; // was next before swap
        }
        swap(head, tail);
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