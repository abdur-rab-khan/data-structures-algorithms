#include <algorithm>
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
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }

   private:
    int diameter = 0;

    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight  = height(node->left);
        int rightHeight = height(node->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    Solution sol;

    TreeNode* root    = new TreeNode(1);
    root->left        = new TreeNode(2);
    root->right       = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Longest diameter of this tree is: " << sol.diameterOfBinaryTree(root)
              << std::endl;

    return 0;
}
