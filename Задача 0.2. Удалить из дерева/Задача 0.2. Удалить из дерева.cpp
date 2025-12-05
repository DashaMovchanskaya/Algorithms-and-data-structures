#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ofstream out("output.txt");

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {};
};

Node* findMin(Node* n) {
    if (n->left) {
        return findMin(n->left);
    }
    else {
        return n;
    }
}

Node* nodeDelete(Node* node, int del) {
    if (node == nullptr) {
        return nullptr;
    }
    if (del < node->key) {
        node->left = nodeDelete(node->left, del);
        return node;
    }
    else if (del > node->key) {
        node->right = nodeDelete(node->right, del);
        return node;
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            return nullptr;
        }
        else if (node->right == nullptr) {
            return node->left;
        }
        else if (node->left == nullptr) {
            return node->right;
        }
        else {
            int minKey = findMin(node->right)->key;
            node->key = minKey;
            node->right = nodeDelete(node->right, minKey);
            return node;
        }
    }
}

void preOrderTraversal(Node* n) {
    if (n != nullptr) {
        out << n->key << "\n";
        preOrderTraversal(n->left);
        preOrderTraversal(n->right);
    }
}

void insert(Node* n, int key) {
    if (key < n->key) {
        if (n->left == nullptr) {
            Node* node = new Node(key);
            n->left = node;
        }
        else {
            insert(n->left, key);
        }
    }
    else if (key > n->key) {
        if (n->right == nullptr) {
            Node* node = new Node(key);
            n->right = node;
        }
        else {
            insert(n->right, key);
        }
    }
}

int main()
{
    ifstream in("input.txt");

    int del;
    in >> del;

    int k;
    in >> k;

    Node* head = new Node(k);

    while (in >> k) {
        insert(head, k);
    }

    in.close();

    head = nodeDelete(head, del);

    preOrderTraversal(head);
    out.close();

    return 0;
}



