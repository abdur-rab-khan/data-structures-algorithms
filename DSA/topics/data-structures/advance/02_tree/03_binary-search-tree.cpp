/*
+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                        🌲 Binary Search Tree (BST)                                                                       |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                                          |
| 🟡 Binary Search Tree (BST) is a tree data structure that stores data in a structured manner, like "always left child must be smaller than it's parent", "always right"  |
|    "must be greater than it's parent".                                                                                                                                   |
|                                                                                                                                                                          |
|        8                                                                                                                                                                 |
|       / \                                                                                                                                                                |
|      3  10                                                                                                                                                               |
|     / \  \                                                                                                                                                               |
|    1  6  14                                                                                                                                                              |
|                                                                                                                                                                          |
| 🔷 Look, 3 (left child) < 8 (parent) ⏭️ 10 (right child) > 8 (parent) ⏭️ 1 (left child) < 3 (parent) ⏭️ 6 (right child) > 3 (parent) ⏭️ 14 (right child) > 10 (parent)  |
|                                                                                                                                                                          |
| 🔶 BST Operations:                                                                                                                                                       |
|    🔸 Insert: So the insert here is really simple we find place where "val" fits, either on left/right side.                                                             |
|    🔸 Search: Go either left/right based on the target if greater than left move to right otherwise move to left.                                                        |
|    🔸 Remove: Deleting Node in BST, is little bit tricky because after deleting we need to shift the tree to fill the gap, there will be three conditions while deleting |
|               1. Target don't have any child in this condition, we simple return nullptr no need to shift anything                                                       |
|               2. Target have either left child, right child, it's also simple because once we delete it we simple get once of the child in a place of target.            |
|               3. Target have two child, it's the tricker in this condition we try to find the "min node" replace the removed node data with the "min node" one,          |
|                  and we again delete "min node" data, and always "min node" will going to lie between "case 1, case 2", because the "min node" will always smaller       |
|                  means it's the last node which have only right node, because if they have left node than it never be a "min node".                                      |
|                                                                                                                                                                          |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <iostream>
#include <queue>

struct Node {
    int   data;
    Node* left;
    Node* right;
    explicit Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
   public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() { destroyTree_(root); }

    Node* insert(int val) {
        root = insert_(root, val);
        return root;
    }

    Node* search(int target) { return search_(root, target); }

    void remove(int target) { root = deleteNode_(root, target); }

    void printNodes() { printNodes_(root); }

   private:
    Node* root;

    Node* search_(Node* root, int target) {
        if (root == nullptr) {
            return root;
        }

        if (root->data == target) {
            return root;
        }

        return root->data > target ? search_(root->left, target) : search_(root->right, target);
    }

    Node* insert_(Node* root, int val) {
        if (root == nullptr) {
            return new Node(val);
        }

        if (val < root->data) {
            root->left = insert_(root->left, val);
        } else {
            root->right = insert_(root->right, val);
        }

        return root;
    }

    Node* deleteNode_(Node* root, int target) {
        if (root == nullptr) {
            return root;
        }

        if (root->data == target) {
            if (root->left == nullptr && root->right == nullptr) {
                // Case 1: No Children found
                delete root;
                return nullptr;
            } else if (root->left != nullptr && root->right != nullptr) {
                // Case 3: Two Children found
                Node* successor = findMin_(root->right);
                root->data      = successor->data;
                root->right     = deleteNode_(root->right, successor->data);

                return root;
            } else {
                // Case 2: One Children found
                Node* child = root->left == nullptr ? root->right : root->left;

                delete root;
                return child;
            }
        }

        if (root->data > target) {
            root->left = deleteNode_(root->left, target);
        } else if (root->data < target) {
            root->right = deleteNode_(root->right, target);
        }

        return root;
    }

    Node* findMin_(Node* node) {
        if (node->left == nullptr) {
            return node;
        }
        return findMin_(node->left);
    }

    void printNodes_(Node* root) {
        if (root == nullptr) {
            return;
        }

        std::cout << "Nodes are: ";

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            std::cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }

            if (current->right) {
                q.push(current->right);
            }
        }
    }

    void destroyTree_(Node* node) {
        if (node == nullptr) {
            return;
        }

        destroyTree_(node->left);
        destroyTree_(node->right);

        delete node;
    }
};

int main() {
    BinarySearchTree bst;
    for (const int& num : {10, 5, 15, 12, 20, 13}) {
        bst.insert(num);
    }
    bst.printNodes();

    if (bst.search(13)) {
        std::cout << "\n13 found\n";
    }

    return 0;
}
