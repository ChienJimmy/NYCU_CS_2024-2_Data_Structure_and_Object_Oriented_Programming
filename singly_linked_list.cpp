#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAt(int index, int val) {
        Node* newNode = new Node(val);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp && i < index - 1; i++)
            temp = temp->next;
        if (!temp) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteVal(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};