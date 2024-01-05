// https://leetcode.com/problems/diameter-of-binary-tree
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter{0};
        depthOfBinaryTree(root, diameter);
        return diameter;
    }

    int depthOfBinaryTree(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }
        int left_depth{depthOfBinaryTree(root->left, diameter)};
        int right_depth{depthOfBinaryTree(root->right, diameter)};
        diameter = std::max(diameter, left_depth + right_depth);
        return 1 + std::max(left_depth, right_depth);
    }
};


TEST_CASE("NO_TEST") {}
