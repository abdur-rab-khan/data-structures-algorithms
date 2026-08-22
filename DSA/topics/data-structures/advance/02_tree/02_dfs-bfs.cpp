/*
+--------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                      🌲 TREE TRAVERSING                                                                      |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                                              |
| 🟡 DFS (Depth First Search): A DFS is a traversing technique where pick a node and deep as you can until reaches dead end, then check other node.            |
|                                                                                                                                                              |
|    🔶 Types of DFS (One Specify Rule for printing):                                                                                                          |
|                    1. InOrder: Left -> Node (Print) -> Right                                                                                                 |
|                    1. PreOrder: Node (Print) -> Left -> Right                                                                                                |
|                    1. PostOrder: Left -> Right -> Node (Print)                                                                                               |
|                                                                                                                                                              |
|                                                                                                                                                              |
| 🟡 BFS (Breadth First Search): Unlike DFS (go deeper first), In BFS we just go "level-by-level" like reading a book line by line like "left to right"        |
|                                then "top to bottom". To implement this we use "queue " Data Structure.                                                       |
|                                                                                                                                                              |
+--------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int   data;
    Node* left;
    Node* right;
    explicit Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

namespace dfs {
    void inOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void preOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node* node) {
        if (node == nullptr) {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }

    void main() {
        Node* root       = new Node(1);
        root->left       = new Node(2);
        root->right      = new Node(3);
        root->left->left = new Node(4);
        // root->left->right = new Node(6);

        std::cout << "DFS: " << std::endl;
        std::cout << "In Order: ";
        inOrder(root);

        std::cout << std::endl << "Pre Order: ";
        preOrder(root);

        std::cout << std::endl << "Post Order: ";
        postOrder(root);
    }
};  // namespace dfs

namespace bfs {
    void bfsS(Node* node) {
        if (node == nullptr) {
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            std::cout << front->data << " ";

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }

    void main() {
        Node* root       = new Node(1);
        root->left       = new Node(2);
        root->right      = new Node(3);
        root->left->left = new Node(4);

        std::cout << std::endl << std::endl << "BFS: " << std::endl;
        bfs::bfsS(root);
    }
};  // namespace bfs

int main() {
    dfs::main();
    bfs::main();
    return 0;
}
