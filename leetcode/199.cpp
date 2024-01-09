// https://leetcode.com/problems/binary-tree-right-side-view
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
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> ret;
        std::queue<std::pair<TreeNode*, std::size_t>> queue;
        queue.push({root, 0});
        while (!queue.empty()) {
            auto [node, level] = queue.front();
            queue.pop();
            if (node == nullptr) {
                continue;
            }
            if (level >= ret.size()) {
                ret.push_back(0);
            }
            ret[level] = node->val;
            queue.push({node->left, level+1});
            queue.push({node->right, level+1});
        }
        return ret;
    }
};


TEST_CASE("NO_TEST") {}
