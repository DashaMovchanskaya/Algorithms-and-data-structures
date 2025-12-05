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

    int k;
    in >> k;
  
    Node* head = new Node(k);

    while (in >> k) {
        insert(head, k);
    }

    in.close();

    preOrderTraversal(head);
    out.close();

    return 0;
}


