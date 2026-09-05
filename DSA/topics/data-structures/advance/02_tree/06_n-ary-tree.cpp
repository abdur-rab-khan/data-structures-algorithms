/*
 * 🟡 N-ary tree is a type of tree data structure where they don't have fixed number of children's like in "binary tree", they might have "n" number of children.
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int                    data;
    std::vector<TreeNode*> children;
    explicit TreeNode(int data, std::vector<TreeNode*> nodes = {}) : data(data), children(nodes) {}
};

void dfs(TreeNode* tree) {
    if (tree == nullptr) {
        return;
    }
    std::cout << tree->data << " ";
    for (TreeNode* node : tree->children) {
        dfs(node);
    }
}

void bfs(TreeNode* tree) {
    if (tree == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(tree);

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();

        std::cout << front->data << " ";
        for (TreeNode* node : front->children) {
            q.push(node);
        }
    }
}

int getMaxDepth(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int maxDepth = 1;
    for (TreeNode* n : node->children) {
        int depth = 1 + getMaxDepth(n);
        maxDepth  = std::max(maxDepth, depth);
    }

    return maxDepth;
}

int main() {
    TreeNode* root = new TreeNode(
        2, {
               new TreeNode(5),
               new TreeNode(8),
               new TreeNode(9),
               new TreeNode(10,
                            {
                                new TreeNode(110, {new TreeNode(1110, {new TreeNode(500)})}),
                                new TreeNode(111),
                                new TreeNode(113),
                            }),
               new TreeNode(15),
               new TreeNode(12),
           });

    std::cout << "DFS: ";
    dfs(root);
    std::cout << std::endl;

    std::cout << "BFS: ";
    bfs(root);
    std::cout << std::endl;

    std::cout << "Max depth: " << getMaxDepth(root) << std::endl;

    return 0;
}
