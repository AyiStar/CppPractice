// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) {
        int curr_order{0}, val{-1};
        inorderTraverse(root, curr_order, k, val);
        return val;
    }

private:
    void inorderTraverse(TreeNode* root, int& curr_order, const int& stop_order, int& val) {
        if (root == nullptr) {
            return;
        }
        inorderTraverse(root->left, curr_order, stop_order, val);
        curr_order++;
        if (curr_order == stop_order) {
            val = root->val;
            return;
        } else if (curr_order > stop_order) {
            return;
        }
        inorderTraverse(root->right, curr_order, stop_order, val);
        return;
    }
};


TEST_CASE("NO_TEST") {}
