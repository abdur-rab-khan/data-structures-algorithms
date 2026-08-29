#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        const bool isValidNode = (p != nullptr && q != nullptr) && (p->val == q->val);
        if (!isValidNode) {
            return false;
        }

        const bool isValidChild = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        if (isValidChild) {
            return true;
        }

        return false;
    }
};

int main() {
    TreeNode* tree1         = new TreeNode(1);
    tree1->left             = new TreeNode(2);
    tree1->right            = new TreeNode(3);
    tree1->left->left       = new TreeNode(4);
    tree1->left->right      = new TreeNode(6);
    tree1->left->left->left = new TreeNode(5);
    /*
                 1
                / \
               2   3
              / \
             4   6
            /
           5
     */

    TreeNode* tree2 = new TreeNode(1);
    tree2->left     = new TreeNode(2);
    tree2->right    = new TreeNode(3);
    /*
             1
            / \
           2   3
    */

    Solution sol;
    std::cout << "Is Identical: " << (sol.isSameTree(tree1, tree1) ? "true" : "false") << std::endl;
    std::cout << "Is Identical: " << (sol.isSameTree(tree1, tree2) ? "true" : "false") << std::endl;

    return 0;
}
