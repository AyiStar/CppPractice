// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <queue>
#include <utility>


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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<std::vector<int>> ret;
        std::queue<std::pair<TreeNode*, std::size_t>> queue;
        queue.push({root, 0});
        while (!queue.empty()) {
            auto [node, level] = queue.front();
            queue.pop();
            if (level >= ret.size()) {
                ret.push_back(std::vector<int>{});
            }
            ret[level].push_back(node->val);
            if (node->left != nullptr) {
                queue.push({node->left, level+1});
            }
            if (node->right != nullptr) {
                queue.push({node->right, level+1});
            }
        }
        return ret;
    }
};


TEST_CASE("NO_TEST") {}
