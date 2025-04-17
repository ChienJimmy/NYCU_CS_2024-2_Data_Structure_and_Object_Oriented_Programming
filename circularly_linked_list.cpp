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
    CNode* cursor;  // The cursor points to a node in the list

public:
    CircularLinkedList() : cursor(nullptr) {}

    // Insert a new node after the cursor
    void insert(int val) {
        CNode* newNode = new CNode(val);
        if (!cursor) {
            newNode->next = newNode;
            cursor = newNode;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
    }

    // Delete the node after the cursor
    void deleteNext() {
        if (!cursor) return;
        CNode* temp = cursor->next;
        if (temp == cursor) { // Only one node
            delete cursor;
            cursor = nullptr;
        } else {
            cursor->next = temp->next;
            delete temp;
        }
    }

    // Delete the node the cursor points to
    void deleteCursor() {
        if (!cursor) return;
        CNode* current = cursor;

        // Case 1: Only one node
        if (cursor->next == cursor) {
            delete cursor;
            cursor = nullptr;
            return;
        }

        // Case 2: Find the node before cursor
        CNode* prev = cursor;
        while (prev->next != cursor)
            prev = prev->next;

        prev->next = cursor->next;
        CNode* temp = cursor;
        cursor = cursor->next;  // Move cursor forward
        delete temp;
    }

    // Move cursor to the next node
    void advance() {
        if (cursor) {
            cursor = cursor->next;
        }
    }

    // Search for a value starting from cursor
    bool search(int val) {
        if (!cursor) return false;
        CNode* temp = cursor;
        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != cursor);
        return false;
    }

    // Display all nodes starting from cursor
    void display() {
        if (!cursor) {
            cout << "(empty list)\n";
            return;
        }

        CNode* start = cursor;
        do {
            cout << start->data << " -> ";
            start = start->next;
        } while (start != cursor);
        cout << "(back to cursor)\n";
    }
};