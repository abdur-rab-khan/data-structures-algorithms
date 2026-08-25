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
