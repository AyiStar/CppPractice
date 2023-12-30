// https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <catch2/catch_test_macros.hpp>
#include <vector>


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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ret;
        inorderTraversalHelper(root, ret);
        return ret;
    }

private:
    void inorderTraversalHelper(TreeNode* root, std::vector<int>& ret) {
        if (root == nullptr) {
            return;
        }
        inorderTraversalHelper(root->left, ret);
        ret.push_back(root->val);
        inorderTraversalHelper(root->right, ret);
    }
};


TEST_CASE("EXAMPLE") {
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    REQUIRE(Solution().inorderTraversal(root) == std::vector<int>{1, 3, 2});
}