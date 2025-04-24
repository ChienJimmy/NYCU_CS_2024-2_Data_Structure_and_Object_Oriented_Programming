#include <iostream>
using namespace std;

struct ListNode {
// TODO
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // TODO
    int v1, v2;
    v1 = l1->val;
    v2 = l2->val;
    ListNode* head = nullptr;
    ListNode* curr = nullptr;
    if (v1 < v2) {
        head = l1;
        curr = l1;
        l1 = l1->next;
    } else {
        head = l2;
        curr = l2;
        l2 = l2->next;
    }
    while (true){
        if (l1 == nullptr && l2 == nullptr) {
            break;
        }
        if (l1 == nullptr) {
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
            continue;
        }
        if (l2 == nullptr) {
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
            continue;
        }
        v1 = l1->val;
        v2 = l2->val;
        if (v1 < v2) {
            curr->next = l1;
            curr = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
        }
    }
    return head;
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

ListNode* createList() {
    // TODO
    int n, val;
    cin >> n >> val;
    ListNode* head = new ListNode(val);
    ListNode* temp = head;
    for (int i = 1; i < n; i++){
        cin >> val;
        ListNode* newNode = new ListNode(val);
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = nullptr;
    return head;
}

int main() {
    ListNode* l1 = createList();
    printList(l1);
    ListNode* l2 = createList();
    printList(l2);

    int parttwo;
    cin >> parttwo;
    if(parttwo == 1){
        ListNode* mergedList = mergeTwoLists(l1, l2);
        printList(mergedList);
    }

    return 0;
}