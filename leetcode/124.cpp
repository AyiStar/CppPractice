// https://leetcode.com/problems/binary-tree-maximum-path-sum
#include <catch2/catch_test_macros.hpp>
#include <limits>


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
    int maxPathSum(TreeNode* root) {
        max_sum_ = std::numeric_limits<int>::min();
        maxPathSumHelper(root);
        return max_sum_;
    }

private:

    int maxPathSumHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_gain = std::max(maxPathSumHelper(root->left), 0);
        int right_gain = std::max(maxPathSumHelper(root->right), 0);
        int curr_gain = root->val + std::max(left_gain, right_gain);
        max_sum_ = std::max(max_sum_, root->val + left_gain + right_gain);
        return curr_gain;
    }

    int max_sum_{std::numeric_limits<int>::min()};
};


TEST_CASE("NO_TEST") {}
