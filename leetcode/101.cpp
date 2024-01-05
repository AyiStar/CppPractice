// https://leetcode.com/problems/symmetric-tree
#include <catch2/catch_test_macros.hpp>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // assume root not nullptr
        return mirrorSubTrees(root->left, root->right);
    }

    bool mirrorSubTrees(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        return (
            (left->val == right->val)
            && mirrorSubTrees(left->left, right->right)
            && mirrorSubTrees(left->right, right->left)
        );
    }
};


TEST_CASE("NO_TEST") {}
