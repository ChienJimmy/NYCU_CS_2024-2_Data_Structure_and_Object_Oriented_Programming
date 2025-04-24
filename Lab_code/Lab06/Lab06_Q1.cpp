#include <iostream>
using namespace std;

class ListNode {
// TODO
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* reverseList(ListNode* head) {
    // TODO
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;
    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(ListNode* head) {
    // TODO
    ListNode* current = head;
    while (current->next != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << current->val << "\n";
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);
    //1 2 3 4 5

    ListNode* reversedHead = reverseList(head);

    printList(reversedHead);
    //5 4 3 2 1

    return 0;
}