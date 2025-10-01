#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    vector<Node*> children;

    Node(int data) { this->data = data; }
};

// Adding element in the node
void addChild(Node* node, int value) {
    Node* child = new Node(value);
    node->children.push_back(child);
}

// Print tree
void printTree(Node* node, int level = 0) {
    if (node == nullptr)
        return;

    // Printing current node with indentation
    for (int i = 0; i < level; i++)
        cout << "--";
    cout << node->data << "\n";

    // Recursively printing it's childrens
    for (Node* node : node->children) {
        printTree(node, level + 1);
    }
}

// Searching element in the node
bool searchNode(Node* root, int key) {
    // If root is nullptr nothing there in root
    if (root == nullptr)
        return false;

    // If key found in root element
    if (root->data == key)
        return true;

    for (Node* child : root->children) {
        if (searchNode(child, key))
            return true;
    }

    return false;
}

int main() {
    // Creating root node
    Node* root = new Node(1);

    // Add Children
    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 4);

    // Adding GrandChildrens
    addChild(root->children[0], 5);  // Children of node 2
    addChild(root->children[0], 6);  // Children of node 2
    addChild(root->children[2], 7);  // Children of node 4

    // Printing tree
    printTree(root);

    // Checking 6 is present or not
    int key = 6;
    if (searchNode(root, key)) {
        cout << key << " found in tree.\n";
    } else {
        cout << key << " not found in tree.\n";
    }

    return 0;
}