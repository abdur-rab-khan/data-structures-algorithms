#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

#include "../../../../dsa_utils.h"

using namespace std;

struct TreeNode {
    int       data;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

vector<int> rightView(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<int> rightNodes;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();

            if (i == levelSize - 1) {
                rightNodes.push_back(currentNode->data);
            }

            if (currentNode->left)
                q.push(currentNode->left);
            if (currentNode->right)
                q.push(currentNode->right);
        }
    }

    return rightNodes;
}

vector<int> leftView(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<int> leftNode;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();

            if (i == 0) {
                leftNode.push_back(currentNode->data);
            }

            if (currentNode->left)
                q.push(currentNode->left);
            if (currentNode->right)
                q.push(currentNode->right);
        }
    }

    return leftNode;
}

vector<int> topView(TreeNode* root) {
    if (!root) {
        return {};
    }

    vector<int> topNodes;
    topNodes.push_back(root->data);

    queue<std::pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));

    std::unordered_set<int> nodeSet;
    nodeSet.insert(0);

    while (!q.empty()) {
        auto currentNode = q.front();
        int  parentHd    = currentNode.second;
        q.pop();

        if (currentNode.first->left) {
            int leftHd = parentHd - 1;
            if (nodeSet.find(leftHd) == nodeSet.end()) {
                topNodes.push_back(currentNode.first->left->data);
            }
            nodeSet.insert(leftHd);
            q.push(make_pair(currentNode.first->left, leftHd));
        }

        if (currentNode.first->right) {
            int rightHd = parentHd + 1;
            if (nodeSet.find(rightHd) == nodeSet.end()) {
                topNodes.push_back(currentNode.first->right->data);
            }
            nodeSet.insert(rightHd);
            q.push(make_pair(currentNode.first->right, rightHd));
        }
    }

    return topNodes;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left     = new TreeNode(2);
    root->right    = new TreeNode(3);

    root->right->right = new TreeNode(6);

    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->left->right->right = new TreeNode(7);

    print(rightView(root), "Nodes on right view are: ");
    print(leftView(root), "Nodes on right view are: ");
    print(topView(root), "Nodes on top view are: ");

    TreeNode* root1           = new TreeNode(1);
    root1->left               = new TreeNode(2);
    root1->left->right        = new TreeNode(3);
    root1->left->right->right = new TreeNode(4);

    print(topView(root1), "Nodes on top view are: ");

    return 0;
}
