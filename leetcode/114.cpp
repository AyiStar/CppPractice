// https://leetcode.com/problems/flatten-binary-tree-to-linked-list
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
    void flatten(TreeNode* root) {
        if (root != nullptr) {
            flattenSubtree(root);
        }
    }

private:
    TreeNode* flattenSubtree(TreeNode* root) {
        // returns the pointer to the last node after flattening
        // assume root != nullptr
        TreeNode *left{root->left}, *right{root->right};
        TreeNode *last{root};
        if (left != nullptr) {
            TreeNode *tmp = flattenSubtree(left);
            last->right = left;
            last = tmp;
        }
        if (right != nullptr) {
            TreeNode *tmp = flattenSubtree(right);
            last->right = right;
            last = tmp;
        }
        root->left = nullptr;
        return last;
    }
};


TEST_CASE("NO_TEST") {}
