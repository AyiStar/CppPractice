// https://leetcode.cn/problems/validate-binary-search-tree
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
    bool isValidBST(TreeNode* root) {
        last_ = nullptr;
        bool is_valid = inorderVisitSorted(root);
        if (last_ != nullptr) {
            delete last_;
            last_ = nullptr;
        }
        return is_valid;
    }

private:
    bool inorderVisitSorted(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorderVisitSorted(root->left)) {
            return false;
        }
        if (last_ != nullptr && root->val <= *last_) {
            return false;
        }
        if (last_ == nullptr) {
            last_ = new int();
        }
        *last_ = root->val;
        if (!inorderVisitSorted(root->right)) {
            return false;
        }
        return true;
    }

    int *last_;
};


TEST_CASE("NO_TEST") {}
