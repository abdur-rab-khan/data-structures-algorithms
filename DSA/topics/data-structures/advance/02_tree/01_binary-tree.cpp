/*
+--------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                            🌲TREE                                                                            |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                              |
| 🟡 A Tree a non-linear data structure that stores data in a tree form, where items (Node) are connected with each other using (Edges) like a "family tree"   |
|    "folder structure" etc.                                                                                                                                   |
|                                                                                                                                                              |
|     🔶 Key Terminologies:                                                                                                                                    |
|           🔸 Node:    Box/Item that holds (currentData + links to children).                                                                                 |
|           🔸 Root:    The topmost node.                                                                                                                      |
|           🔸 Parent:  A parent that has children's below                                                                                                     |
|           🔸 Child:   A node directly below a parent                                                                                                         |
|           🔸 Leaf:    A node with no children                                                                                                                |
|           🔸 Edge:    The connection line between a parent and child                                                                                         |
|           🔸 Depth:   How many steps a node from the root                                                                                                    |
|           🔸 Height:  How many steps from a node down to the deepest leaf.                                                                                   |
|                                                                                                                                                              |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/
#include <iostream>
#include <vector>

#include "../../../../dsa_utils.h"

using namespace std;

struct Node {
    int   data;
    Node* left;
    Node* right;
    explicit Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

bool isLeaf(Node* node) {
    const bool isValidLeaf = node != nullptr && (node->left == nullptr && node->right == nullptr);
    if (isValidLeaf) {
        return true;
    }
    return false;
}

int countNode(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return 1 + countNode(node->left) + countNode(node->right);
}

int main() {
    Node* root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(6);

    print(isLeaf(root), "Is root is a Leaf Node: ");
    print(isLeaf(root->right), "Is root->right is a Leaf Node: ");
    print(countNode(root), "Total nodes are: ");

    return 0;
}
