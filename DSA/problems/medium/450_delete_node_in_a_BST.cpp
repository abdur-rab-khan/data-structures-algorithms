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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (root->val == key) {
            if (root->left && root->right) {
                // 🟡 Always we find min from right because, if we do with left it will make our BST invalid.
                /*
                         5
                        / \
                       3   6
                      / \   \
                     2   4   7

                🔶 For example want to remove "5", if we go toward left than min will be 2 and if we got with right than it will be 6

                        2
                       / \
                      3   6
                       \   \
                        4   7

                    🔷 Invalid BST tree

                        6
                       / \
                      3   7
                     / \
                    2   4

                    🔷 Valid BST tree
                */
                TreeNode* minNode = findMin(root->right);
                root->val         = minNode->val;
                root->right       = deleteNode(root->right, minNode->val);

                return root;
            }

            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            } else {
                return root->left == nullptr ? root->right : root->left;
            }
        }

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }

   private:
    TreeNode* findMin(TreeNode* node) {
        if (node->left == nullptr) {
            return node;
        }

        return findMin(node->left);
    }
};

int main() {
    Solution sol;
    print(sol.({}));
    return 0;
}
