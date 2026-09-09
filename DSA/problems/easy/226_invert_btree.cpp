#include <utility>

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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main() {
    Solution sol;

    TreeNode* root = new TreeNode(1);

    root->left        = new TreeNode(2);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(8);

    root->right        = new TreeNode(3);
    root->right->left  = new TreeNode(9);
    root->right->right = new TreeNode(12);

    // TreeNode* invertedTree = sol.invertTree(root);

    return 0;
}
