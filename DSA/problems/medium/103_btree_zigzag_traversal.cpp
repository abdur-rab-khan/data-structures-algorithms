#include <deque>
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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        bool                          reverse = false;
        std::vector<std::vector<int>> result;

        std::deque<TreeNode*> dq;
        dq.push_back(root);

        while (!dq.empty()) {
            std::vector<int> current;
            int              levelSize = dq.size();

            for (int i = 0; i < levelSize; ++i) {
                if (!reverse) {
                    TreeNode* node = dq.front();
                    current.push_back(node->val);

                    if (node->left) {
                        dq.push_back(node->left);
                    }

                    if (node->right) {
                        dq.push_back(node->right);
                    }

                    dq.pop_front();
                } else {
                    TreeNode* node = dq.back();
                    current.push_back(node->val);

                    if (node->right) {
                        dq.push_front(node->right);
                    }

                    if (node->left) {
                        dq.push_front(node->left);
                    }

                    dq.pop_back();
                }
            }

            reverse = !reverse;
            if (!current.empty()) {
                result.push_back(current);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(3);

    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    print(sol.zigzagLevelOrder(root));

    return 0;
}
