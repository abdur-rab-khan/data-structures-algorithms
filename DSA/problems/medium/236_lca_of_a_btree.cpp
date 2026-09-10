#include <iostream>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) {
            return root;
        }

        TreeNode* left  = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left     = new TreeNode(5);
    root->right    = new TreeNode(1);

    root->right->left  = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->left         = new TreeNode(6);
    root->left->right        = new TreeNode(2);
    root->left->right->left  = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    std::cout << "Lowest Common Ancestor is 1: "
              << (sol.lowestCommonAncestor(root, root->right->left, root->right->right)->val == 1
                      ? "true"
                      : "false")
              << std::endl;

    return 0;
}
