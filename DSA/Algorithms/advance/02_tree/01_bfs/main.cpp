#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    vector<Node*> children;

    Node(int data) { this->data = data; }
};

// Add child
void addChild(Node* root, int value) {
    Node* node = new Node(value);
    root->children.push_back(node);
}

// Implementing BFS
bool dfs(Node* root, int key = 0) {
    if (!root)
        return false;

    // Root has same value as key
    if (root->data == key)
        return true;

    for (Node* child : root->children) {
        if (dfs(child, key)) {
            return true;
        }
    }

    return false;
}

int main() {
    Node* node = new Node(1);

    // Adding childrens
    addChild(node, 2);
    addChild(node, 3);
    addChild(node, 4);

    // Adding grand-childrens
    addChild(node->children[0], 22);
    addChild(node->children[0], 33);
    addChild(node->children[2], 1);

    // Searching using dfs
    int key = 6;
    cout << key << " Found: " << dfs(node, key) << endl;

    return 0;
}