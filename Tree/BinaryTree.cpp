#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;

    Node (char c) : data(c), left(nullptr), right(nullptr) {}
};

void preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

void levelorder(Node* node) {
    queue<Node*> q;
    q.push(node);

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

void delete_tree(Node* node) {
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

int main() {
    Node* root = new Node('A');

    root->left = new Node('B');
    root->right = new Node('C');

    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;

    levelorder(root);
    cout << endl;

    delete_tree(root);
}
