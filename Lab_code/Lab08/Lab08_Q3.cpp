#include <iostream>
using namespace std;
class treeNode{
public:
    int data;
    treeNode* parent;
    treeNode* left;
    treeNode* right;

    treeNode(int val) {
        data = val;
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
    friend class BinaryTree;
};
class BinaryTree{
public:
    treeNode* root;
    treeNode* curr;
    BinaryTree() {
        root = nullptr;
    }
    void insert(int val) {
        if (root == nullptr) {
            root = new treeNode(val);
        }
        else {
            curr = root;
            while (true) {
                if (val < curr->data) {
                    if (curr->left == nullptr) {
                        curr->left = new treeNode(val);
                        curr->left->parent = curr;
                        break;
                    }
                    else {
                        curr = curr->left;
                    }
                }
                else {
                    if (curr->right == nullptr) {
                        curr->right = new treeNode(val);
                        curr->right->parent = curr;
                        break;
                    }
                    else {
                        curr = curr->right;
                    }
                }
            }
        }
    }
    void inorder(treeNode* node) {
        cout << "Inorder: ";
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
        cout << "\n";
    }
    void preorder(treeNode* node) {
        cout << "Preorder: ";
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
        cout << "\n";
    }
    void postorder(treeNode* node) {
        cout << "Postorder: ";
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
        cout << "\n";
    }
    int getHeight(treeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);
            return max(leftHeight+1, rightHeight+1);
        }
    }
    void printtree(treeNode* node, int space) {
        if (node == nullptr) {
            return;
        }
        space += 10;
        printtree(node->right, space);
        cout << "\n";
        for (int i = 10; i < space; i++) {
            cout << " ";
        }
        cout << node->data << "\n";
        printtree(node->left, space);
    }
    bool find(int target){
        curr = root;
        while (curr != nullptr) {
            if (curr->data == target){
                return true;
            }
            else if (target < curr->data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        return false;
    }
};
int main(){
    int n;
    cin >> n;
    BinaryTree tree;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    int target;
    cin >> target;
    bool found = tree.find(target);
    if (found) {
        cout << "Found\n";
    }
    else {
        cout << "Not Found\n";
    }
}