#include <iostream>
#include <queue>
#include <vector>

#include "../../dsa_utils.h"

using namespace std;

struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> nodeQueue;
        vector<int>      rightNodes;

        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int queueSize = static_cast<int>(nodeQueue.size());

            for (int i = 0; i < queueSize; ++i) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();

                if (i == queueSize - 1) {
                    rightNodes.push_back(node->val);
                }

                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
        }

        return rightNodes;
    }
};

int main() {
    Solution sol;

    print(sol.rightSideView(nullptr));
    print(sol.rightSideView(new TreeNode(
        1, new TreeNode(2, new TreeNode(4, new TreeNode(5), nullptr), nullptr), new TreeNode(3))));
    print(sol.rightSideView(new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                                         new TreeNode(3, nullptr, new TreeNode(4)))));

    return 0;
}
