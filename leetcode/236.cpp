// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <utility>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        } else if (left == nullptr && right == nullptr) {
            return nullptr;
        } else if (left != nullptr) {
            return left;
        } else {
            return right;
        }
    }

    TreeNode* lowestCommonAncestorOrigin(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<std::pair<TreeNode*, int>> path;
        return lowestCommonAncestorHelper(root, p, q, path);
    }

private:
    using path_t = std::vector<TreeNode*>;
    TreeNode* lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q,
                                    std::vector<std::pair<TreeNode*, int>>& path) {
        if (root == nullptr) {
            return nullptr;
        }
        path.push_back({root, 0});
        if (root == p) {
            for (auto& [node, cnt]: path) {
                cnt++;
            }
        }
        if (root == q) {
            for (auto& [node, cnt]: path) {
                cnt++;
            }
        }
        auto ret = lowestCommonAncestorHelper(root->left, p, q, path);
        if (ret != nullptr) {
            path.pop_back();
            return ret;
        }
        ret = lowestCommonAncestorHelper(root->right, p, q, path);
        if (ret != nullptr) {
            path.pop_back();
            return ret;
        }
        auto [node, cnt] = path.back();
        path.pop_back();
        return (cnt == 2) ? node : nullptr;
    }
};


TEST_CASE("NO_TEST") {}
