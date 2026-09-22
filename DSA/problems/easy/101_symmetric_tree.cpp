#include <deque>

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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> leftNodes;
        deque<TreeNode*> rightNodes;

        leftNodes.push_back(root->left);
        rightNodes.push_back(root->right);

        while (!leftNodes.empty() && !rightNodes.empty()) {
            int size = leftNodes.size();

            while (size--) {
                TreeNode* left  = leftNodes.front();
                TreeNode* right = rightNodes.front();
                leftNodes.pop_front();
                rightNodes.pop_front();

                if (left == nullptr || right == nullptr) {
                    if (left == nullptr && right == nullptr) {
                        continue;
                    } else {
                        return false;
                    }
                }

                if (left->val != right->val) {
                    return false;
                }

                leftNodes.push_back(left->left);
                leftNodes.push_back(left->right);
                rightNodes.push_back(right->right);
                rightNodes.push_back(right->left);
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    TreeNode* root     = new TreeNode(1);
    root->left         = new TreeNode(2);
    root->left->left   = new TreeNode(3);
    root->left->right  = new TreeNode(4);
    root->right        = new TreeNode(2);
    root->right->left  = new TreeNode(4);
    root->right->right = new TreeNode(3);

    print(sol.isSymmetric(root));

    return 0;
}
