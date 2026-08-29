#include <iostream>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        // Subtracting, current val from targetSum to see whether it's equal or not
        targetSum -= root->val;

        // Leaf node, return true if targetSum = 0 else false
        if (!root->left && !root->right) {
            return targetSum == 0;
        }

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left     = new TreeNode(4);
    root->right    = new TreeNode(8);

    root->left->left = new TreeNode(11);

    root->left->left->left  = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left  = new TreeNode(13);
    root->right->right = new TreeNode(4);

    root->right->right->right = new TreeNode(1);

    Solution sol;
    print(sol.hasPathSum(root, 22));

    return 0;
}
