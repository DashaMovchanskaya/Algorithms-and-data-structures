#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

using namespace std;

ofstream out("out.txt");

int MAX_MSL = 1;

struct Node {
    int key;
    Node* left;
    Node* right;
    int h;
    int MSL;
    Node(int k) : key(k), left(nullptr), right(nullptr), h(0), MSL(0) {};
};

Node* delV = new Node(INT_MIN);
vector<Node *> delVs;

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

void PostOrderTraversal(Node* v) {
    if (v != nullptr) {
        PostOrderTraversal(v->right);
        PostOrderTraversal(v->left);
        if (v->left == nullptr && v->right == nullptr) {
            v->h = 0;
            v->MSL = 0;
        }
        else if (v->left != nullptr && v->right == nullptr) {
            v->h = v->left->h + 1;
            v->MSL = v->left->h + 1;
        }
        else if (v->left == nullptr && v->right != nullptr) {
            v->h = v->right->h + 1;
            v->MSL = v->right->h + 1;
        }
        else {
            v->h = max(v->left->h, v->right->h) + 1;
            v->MSL = v->left->h + v->right->h + 2;
        }

        if (v->MSL >= MAX_MSL) {
            MAX_MSL = v->MSL;
        }
    }
}

void PreOrderTraversalMax(Node* v) {
    if (v != nullptr) {
        if (v->MSL == MAX_MSL) {
            delVs.push_back(v);
            if (v->key > delV->key) {
                delV = v;
            }
        }
        PreOrderTraversalMax(v->left); 
        PreOrderTraversalMax(v->right);
    }
}

void PreOrderTraversalOut(Node* v) {
    if (v != nullptr) {
        out << v->key << endl;
        PreOrderTraversalOut(v->left); 
        PreOrderTraversalOut(v->right); 
    }
}

void buildBranch(Node* node, deque<int>& path, bool goLeft) {
    if (node == nullptr) {
        return;
    }

    path.push_back(node->key);

    if (goLeft) {
        if (node->left != nullptr && node->right != nullptr) {
            if (node->left->MSL > node->right->MSL) {
                buildBranch(node->left, path, true); 
            }
            else {
                buildBranch(node->right, path, true);
            }
        }
        else if (node->right != nullptr) {
            buildBranch(node->right, path, true);
        }
        else {
            buildBranch(node->left, path, true); 
        }
    }
    else {
        if (node->right != nullptr && node->left != nullptr) {
            if (node->left->MSL > node->right->MSL) {
                buildBranch(node->left, path, false);
            }
            else {
                buildBranch(node->right, path, false);
            }
        }
        else if (node->left != nullptr) {
            buildBranch(node->left, path, false);
        }
        else {
            buildBranch(node->right, path, false); 
        }
    }
}

deque<int> buildMSL(Node* n) {
    deque<int> path;

    if (n == nullptr) {
        return path;
    }

    deque<int> leftBranch;
    if (n->left != nullptr) {
        buildBranch(n->left, leftBranch, true);
    }

    deque<int> rightBranch;
    if (n->right != nullptr) {
        buildBranch(n->right, rightBranch, false);
    }

    for (int i = leftBranch.size() - 1; i >= 0; i--) {
        path.push_back(leftBranch[i]);
    }
    path.push_back(n->key); 
    for (int key : rightBranch) {
        path.push_back(key);
    }

    return path;
}

int main()
{
    ifstream in("in.txt");

    int k;

    in >> k;

    Node* head = new Node(k);

    while (in >> k) {
        insert(head, k);
    }

    in.close();

    PostOrderTraversal(head);
    PreOrderTraversalMax(head); 

    int maxSum = INT_MIN;
    deque<int> pathMax;
    for (Node* v : delVs) {
        deque<int> path = buildMSL(v);
        int sum = 0;
        for (int i : path) {
            sum += i;
        }
        if (sum > maxSum) {
            delV = v;
            pathMax = path;
            maxSum = sum;
        }
    }

    if (delV->MSL % 2 == 0) {
        int index = pathMax.size() / 2;
        if (pathMax[index] != delV->key) {
            head = nodeDelete(head, pathMax[index]);
        }
    }

    head = nodeDelete(head, delV->key);

    PreOrderTraversalOut(head);
    out.close();

    return 0;
}

