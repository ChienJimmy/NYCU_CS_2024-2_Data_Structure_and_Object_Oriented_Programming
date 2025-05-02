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
            treeNode* parent = nullptr;
            while (curr) {
                parent = curr;
                if (val < curr->data) {
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            treeNode* newNode = new treeNode(val);
            newNode->parent = parent;
            if (val < parent->data) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
        }
    }
    void inorder(treeNode* node) {
        
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
        
    }
    void preorder(treeNode* node) {
        
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
        
    }
    void postorder(treeNode* node) {
        
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
        
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
    cout << "Inorder: ";
    tree.inorder(tree.root);
    cout << "\n";
    cout << "Preorder: ";
    tree.preorder(tree.root);
    cout << "\n";
    cout << "Postorder: ";
    tree.postorder(tree.root);
    cout << "\n";
}