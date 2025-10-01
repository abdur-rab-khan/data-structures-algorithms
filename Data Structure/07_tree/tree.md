# Tree Data Structure

> **Tree Data Structure** is a non-linear data structure usually used to show hierarchical representation of data.

- [Tree Data Structure](#tree-data-structure)
  - [Key Points of Tree Data Structure](#key-points-of-tree-data-structure)
  - [Types of Tree](#types-of-tree)
  - [Basic Terminologies in Tree Data Structure](#basic-terminologies-in-tree-data-structure)
  - [Representation of a Node in Tree Data](#representation-of-a-node-in-tree-data)
  - [Basic Operation in Tree](#basic-operation-in-tree)
    - [`Create and insert:`](#create-and-insert)
    - [`Search:` Searches specific data in tree](#search-searches-specific-data-in-tree)

## Key Points of Tree Data Structure

- Shows collection of elements connected to each other via edges.
- There is exactly one path between any two nodes, this is a major limitation in trees that's why of such cases we use **graphs**.
- Tree is consider as **non-linear data structure** because of it does not store in sequential manner instead of arranged in **hierarchical** or in **multi-level**.
- Following are real world examples of trees:
  - Tag structure in **HTML**.
  - Folder structure in OS.

![tree](https://media.geeksforgeeks.org/wp-content/uploads/20250705194019442821/root.webp)

## Types of Tree

1. **Binary Tree**: Every node has at most two children.
2. **Ternary Tree**: Every node has at most three children.
3. **N-ary Tree**: Every node has at most **"n"** children.

![types-of-tree](https://media.geeksforgeeks.org/wp-content/uploads/20250705182900660299/tree.webp)

## Basic Terminologies in Tree Data Structure

- **Parent Node**: The node which is an immediate predecessor of a node is called the parent node of that node. {B} is the parent node of {D, E}.
- **Child Node**: The node which is the immediate successor of a node is called the child node of that node. Examples: {D, E} are the child nodes of {B}.
- **Root Node**: The topmost node of a tree or the node which does not have any parent node is called the root node. {A} is the root node of the tree. A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.
- **Leaf Node or External Node**: The nodes which do not have any child nodes are called leaf nodes. {I, J, K, F, G, H} are the leaf nodes of the tree.
- **Ancestor of a Node**: Any predecessor nodes on the path of the root to that node are called ancestors of that node. {A,B} are the ancestor nodes of the node {E}.
- **Descendant**: A node x is a descendant of another node y if and only if y is an ancestor of x.
- **Sibling**: Children of the same parent node are called siblings. {D,E} are called siblings.
- **Level of a Node**: The count of edges on the path from the root node to that node. The root node has level 0.
- **Internal Node**: A node with at least one child is called an internal node.
- **Neighbor of a Node**: Parent or child nodes of that node are called neighbors of that node.
- **Subtree**: Any node of the tree along with its descendants.

![tree-example](https://media.geeksforgeeks.org/wp-content/uploads/20250214120937877633/treeTerminologies.webp)

## Representation of a Node in Tree Data

- Tree can be represented using a collection of nodes.
- Each node can be represented with the help of **class** or **struct**.

    ```cpp
    class Node{
        public:
            int data;
            Node* first_child;
            Node* second_child;
            Node* third_child;
            .
            .
            .
            .
            Node* nth_child;

            // using 

            vector<Node*> children;
    } 
    ```

## Basic Operation in Tree

### `Create and insert:` 

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    vector<Node*> children;

    Node(int data) { this->data = data; }
};

void addChild(Node* node, int value) {
    Node* child = new Node(value);
    node->children.push_back(child);
}

int main() {
    // Creating root node
    Node* root = new Node(1);

    // Add Children
    addChild(root, 2);
    addChild(root, 3);
    addChild(root, 4);

    // Adding GrandChildren's
    addChild(root->children[0], 5);  // Children of node 2
    addChild(root->children[0], 6);  // Children of node 2
    addChild(root->children[4], 7);  // Children of node 4

    return 0;
}
```

### `Search:` Searches specific data in tree

```cpp
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
```
