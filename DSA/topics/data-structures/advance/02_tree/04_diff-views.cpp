/*
 +----------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                        🟡 Different View in Tree Data Structure                                                          |
 +----------------------------------------------------------------------------------------------------------------------------------------------------------+
 |                                                                                                                                                          |
 | 🟡 Different Views shows how/what nodes will be visible if we look tree from different angles, it can be either left/right/top/bottom.                   |
 | 🟡 On different views we can see different nodes and some nodes might be hidden due to overlap, let's see all one by one.                                |
 |                                                                                                                                                          |
 |   🔹 Left View:                                                                                                                                          |
 |                 If we look a tree from left side what nodes will be visible and what will be overlap, So only first node from the left will be visible.  |
 |                                                                                                                                                          |
 |   🔹 Right View:                                                                                                                                         |
 |                 If we look a tree from right side what nodes will be visible and what will be overlap, So only first node from the right will be visible |
 |                                                                                                                                                          |
 |   🔷 Example:                                                                                                                                            |
 |                 1                                                                                                                                        |
 |                / \                                                                                                                                       |
 |       👁️      2   3     👁️                                                                                                                              |
 |              / \   \                                                                                                                                     |
 |             5   6   4                                                                                                                                    |
 |                  \   \                                                                                                                                   |
 |                   8   9                                                                                                                                  |
 |                                                                                                                                                          |
 |      👉 If you look from left you can only see 1, 2, 5 and 8, not 3 and 6 because it's overlapping with 5.                                               |
 |      👉 If you look from right you can only see 1, 3, 6 and 8, not 5 because it's overlapping with 6.                                                    |
 |                                                                                                                                                          |
 |   🔹 Top View:                                                                                                                                           |
 |               If we look a tree from top view, what nodes will be visible and what will be overlap.                                                      |
 |                                                                                                                                                          |
 |   🔹 Bottom View:                                                                                                                                        |
 |                 If we look a tree from top view, what nodes will be visible and what will be overlap.                                                    |
 |                                                                                                                                                          |
 |      👉 On above example If you look from top you will be 1, 2, 5, 3 not 6 (hide by 1), 8 (hide by 3), it numbers must be in shorted order my HD.        |
 |         HD (Horizontal Distance) that starts by 0 from the root and for child not will will be (PARENT HD - 1 -> for left), (PARENT HD + 1 -> for right).|
 |                                                                                                                                                          |
 |    🔹 Boundary View:                                                                                                                                     |
 |                     On Boundary view we'll include all the boundary elements:                                                                            |
 |                       🔸 All the left edges nodes                                                                                                        |
 |                       🔸 All the leave edges nodes                                                                                                       |
 |                       🔸 All the right edge nodes (reversed order)                                                                                       |
 |                                                                                                                                                          |
 |      👉 For the above example boundary nodes include [1, 2] (left nodes) + [5, 8, 9] (leave nodes) + [4, 3] (right noes in reversed order)               |
 |                                                                                                                                                          |
 +----------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

#include <map>
#include <queue>
#include <ranges>
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

namespace TreeBoundary {
    namespace {
        static bool isLeaveOrNull(TreeNode* root) {
            return root == nullptr || (!root->left && !root->right);
        }

        static void collectLeftEdges(TreeNode* root, vector<int>& result) {
            if (isLeaveOrNull(root)) {
                return;
            }
            result.push_back(root->data);
            collectLeftEdges(root->left, result);
        }

        static void collectLeaves(TreeNode* root, vector<int>& result) {
            if (root == nullptr) {
                return;
            }
            if (isLeaveOrNull(root)) {
                result.push_back(root->data);
                return;
            }
            collectLeaves(root->left, result);
            collectLeaves(root->right, result);
        }

        static void collectRightEdges(TreeNode* root, vector<int>& result) {
            vector<int> topNodes;
            while (!isLeaveOrNull(root)) {
                topNodes.push_back(root->data);
                root = root->right;
            }
            result.insert(result.end(), topNodes.rbegin(), topNodes.rend());
        }
    }  // namespace

    static vector<int> getBoundaryOfTree(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> result;
        result.push_back(root->data);

        collectLeftEdges(root->left, result);
        collectLeaves(root->left, result);
        collectLeaves(root->right, result);
        collectRightEdges(root->right, result);

        return result;
    }
};  // namespace TreeBoundary

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

    queue<std::pair<int, TreeNode*>> q;
    q.push(make_pair(0, root));

    std::map<int, TreeNode*> nodeMap;
    nodeMap.insert({0, root});

    while (!q.empty()) {
        auto      current     = q.front();
        int       parentHd    = current.first;
        TreeNode* currentNode = current.second;

        if (currentNode->left) {
            int leftHd = parentHd - 1;
            nodeMap.insert({leftHd, currentNode->left});
            q.push(make_pair(leftHd, currentNode->left));
        }

        if (currentNode->right) {
            int rightHd = parentHd + 1;
            nodeMap.insert({rightHd, currentNode->right});
            q.push(make_pair(rightHd, currentNode->right));
        }

        q.pop();
    }

    return nodeMap | std::views::transform([](const auto& p) { return p.second->data; }) |
           std::ranges::to<vector<int>>();
}

vector<int> bottomView(TreeNode* root) {
    if (!root) {
        return {};
    }

    std::queue<std::pair<int, TreeNode*>> nodeQueue;
    nodeQueue.push(make_pair(0, root));

    std::map<int, TreeNode*> nodeMap;
    nodeMap.insert({0, root});

    while (!nodeQueue.empty()) {
        auto      current    = nodeQueue.front();
        int       parentHD   = current.first;
        TreeNode* parentNode = current.second;

        if (parentNode->left) {
            int leftHD = parentHD - 1;
            nodeMap.insert_or_assign(leftHD, parentNode->left);
            nodeQueue.push(make_pair(leftHD, parentNode->left));
        }

        if (parentNode->right) {
            int rightHD = parentHD + 1;
            nodeMap.insert_or_assign(rightHD, parentNode->right);
            nodeQueue.push(make_pair(rightHD, parentNode->right));
        }

        nodeQueue.pop();
    }

    return nodeMap | std::views::transform([](const auto& p) { return p.second->data; }) |
           std::ranges::to<vector<int>>();
}

void boundaryView() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);

    root->left->left = new TreeNode(4);

    root->left->right = new TreeNode(5);

    root->left->right->left       = new TreeNode(11);
    root->left->right->left->left = new TreeNode(8);

    root->left->right->right        = new TreeNode(10);
    root->left->right->right->left  = new TreeNode(9);
    root->left->right->right->right = new TreeNode(15);

    root->right               = new TreeNode(3);
    root->right->right        = new TreeNode(6);
    root->right->right->right = new TreeNode(20);

    print(TreeBoundary::getBoundaryOfTree(root), "Boundary Elements are: ");
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
    print(bottomView(root), "Nodes on bottom view are: ");

    TreeNode* root1           = new TreeNode(1);
    root1->left               = new TreeNode(2);
    root1->left->right        = new TreeNode(3);
    root1->left->right->right = new TreeNode(4);

    print(topView(root1), "Nodes on top view are: ");
    print(bottomView(root1), "Nodes on bottom view are: ");

    boundaryView();

    return 0;
}
