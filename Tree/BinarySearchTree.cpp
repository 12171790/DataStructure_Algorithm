#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int n) : data(n), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root = nullptr;

public:
    ~BinarySearchTree() {
        delete_tree(root);
    }

    void insert(int value) {
        if (root == NULL) {
            root = new Node(value);
        } else {
            insert_impl(root, value);
        }
    }

    Node* find(int value) {
        return find_impl(root, value);
    }

    void inorder() {
        inorder_impl(root);
    }

    void erase(int value) {
        root = erase_impl(root, value);
    }

private:
    void insert_impl(Node* curr, int value) {
        if (value < curr->data) {
            if (!curr->left) {
                curr->left = new Node(value);
            } else {
                insert_impl(curr->left, value);
            }
        } else {
            if (!curr->right) {
                curr->right = new Node(value);
            } else {
                insert_impl(curr->right, value);
            }
        }
    }

    Node* find_impl(Node* curr, int value) {
        if (curr == nullptr) {
            return nullptr;
        }

        if (curr->data == value) {
            return curr;
        } else {
            if (curr->data > value) {
                return find_impl(curr->left, value);
            } else {
                return find_impl(curr->right, value);
            }
        }
    }

    void inorder_impl(Node* curr) {
        if (curr != nullptr) {
            inorder_impl(curr->left);

            cout << curr->data << " ";

            inorder_impl(curr->right);
        }
    }

    Node* erase_impl(Node* curr, int value) {
          if (!curr) return nullptr;

          if (value < curr->data) {
            curr->left = erase_impl(curr->left, value);
          } else if (value > curr->data) {
            curr->right = erase_impl(curr->right, value);
          } else {
            if (curr->right && curr->left) {
                auto succ = successor(curr);
                curr->data = succ->data;
                curr->right = erase_impl(curr->right, succ->data);
            } else {
                auto tmp = curr->left ? curr->left : curr->right;

                delete curr;
                return tmp;
            }
          }
    }

    Node* successor(Node* curr) {
        auto node = curr->right;

        while (node && node->left) {
            node = node->left;
        }

        return node;
    }

    void delete_tree(Node* curr) {
        if (curr != nullptr) {
            delete_tree(curr->left);
            delete_tree(curr->right);
            delete curr;
        }
    }

};

int main() {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(14);
    bst.insert(5);
    bst.insert(7);
    bst.insert(18);
    bst.insert(4);
    bst.insert(6);
    bst.insert(20);
    bst.insert(16);

    bst.inorder();
    cout << endl;

    if (bst.find(7)) {
        cout << "7 is found" << endl;
    }

    if (!bst.find(15)) {
        cout << "15 is not found" << endl;
    }

    bst.insert(9);
    bst.insert(12);
    bst.inorder();
    cout << endl;

    bst.erase(4);
    bst.erase(5);
    bst.erase(14);
    bst.inorder();
    cout << endl;

    bst.insert(15);
    bst.erase(10);
    bst.inorder();
    cout << endl;
}