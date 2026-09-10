#include <queue>
#include <vector>

#include "../../dsa_utils.h"

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        std::vector<std::vector<int>> result;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            std::vector<int> currentNodes;
            int              currentLevel = q.size();

            for (int i = 0; i < currentLevel; ++i) {
                TreeNode* top = q.front();
                q.pop();

                currentNodes.push_back(top->val);

                if (top->left) {
                    q.push(top->left);
                }

                if (top->right) {
                    q.push(top->right);
                }
            }

            if (!currentNodes.empty()) {
                result.push_back(currentNodes);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    TreeNode* root     = new TreeNode(3);
    root->left         = new TreeNode(9);
    root->right        = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    print(sol.levelOrder(root));

    return 0;
}
