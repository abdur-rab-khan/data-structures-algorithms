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
    int kthSmallest(TreeNode* root, int k) {
        int visitedCount = 1;
        int kthValue     = kNotFound;
        traverseInOrder(root, k, visitedCount, kthValue);
        return kthValue;
    }

   private:
    static constexpr int kNotFound = -1;

    void traverseInOrder(TreeNode* node, int k, int& visitedCount, int& kthValue) {
        if (node == nullptr || kthValue != kNotFound) {
            return;
        }

        traverseInOrder(node->left, k, visitedCount, kthValue);
        if (visitedCount == k) {
            kthValue = node->val;
        }
        ++visitedCount;
        traverseInOrder(node->right, k, visitedCount, kthValue);
    }
};

int main() {
    Solution sol;

    TreeNode* root1         = new TreeNode(5);
    root1->left             = new TreeNode(3);
    root1->right            = new TreeNode(6);
    root1->left->left       = new TreeNode(2);
    root1->left->right      = new TreeNode(4);
    root1->left->left->left = new TreeNode(1);

    TreeNode* root2    = new TreeNode(3);
    root2->left        = new TreeNode(1);
    root2->right       = new TreeNode(4);
    root2->left->right = new TreeNode(2);

    print(sol.kthSmallest(root1, 3), "3th smallest value is: ");
    print(sol.kthSmallest(root2, 1), "1th smallest value is: ");

    return 0;
}
