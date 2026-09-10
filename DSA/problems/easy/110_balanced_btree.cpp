
#include <algorithm>
#include <cstdlib>

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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int leftHeight  = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

   private:
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight  = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    Solution sol;

    TreeNode* root     = new TreeNode(3);
    root->left         = new TreeNode(9);
    root->right        = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    TreeNode* root1          = new TreeNode(1);
    root1->left              = new TreeNode(2);
    root1->right             = new TreeNode(3);
    root1->right->left       = new TreeNode(8);
    root1->right->left->left = new TreeNode(10);

    print(sol.isBalanced(root), "Is this tree is balanced: ");
    print(sol.isBalanced(root1), "Is this tree is balanced: ");

    return 0;
}
