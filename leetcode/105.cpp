// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <map>


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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        auto inorder_pos_dict = buildPositionDict(inorder);
        return buildSubtree(preorder, inorder, inorder_pos_dict,
                        0, preorder.size() - 1,
                        0, inorder.size() - 1);
    }

private:
    std::map<int, std::size_t> buildPositionDict(const std::vector<int>& vec) {
        std::map<int, std::size_t> dict;
        for (std::size_t i = 0; i < vec.size(); i++) {
            dict.insert({vec[i], i});
        }
        return dict;
    }

    TreeNode* buildSubtree(const std::vector<int>& preorder,
                           const std::vector<int>& inorder,
                           const std::map<int, std::size_t>& inorder_pos_dict,
                           int preorder_left,
                           int preorder_right,
                           int inorder_left,
                           int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int root_preorder_index = preorder_left;
        int root_inorder_index = inorder_pos_dict.at(preorder[root_preorder_index]);
        int left_subtree_size = root_inorder_index - inorder_left;
        
        int left_preorder_left = root_preorder_index + 1;
        int left_preorder_right = root_preorder_index + left_subtree_size;
        int left_inorder_left = inorder_left;
        int left_inorder_right = root_inorder_index - 1;
        
        int right_preorder_left = left_preorder_right + 1;
        int right_preorder_right = preorder_right;
        int right_inorder_left = root_inorder_index + 1;
        int right_inorder_right = inorder_right;


        TreeNode *subtree= new TreeNode(preorder[root_preorder_index]);
        subtree->left = buildSubtree(preorder, inorder, inorder_pos_dict,
                                    left_preorder_left,
                                    left_preorder_right,
                                    left_inorder_left,
                                    left_inorder_right);
        subtree->right = buildSubtree(preorder, inorder, inorder_pos_dict,
                                    right_preorder_left,
                                    right_preorder_right,
                                    right_inorder_left,
                                    right_inorder_right);
        return subtree;
    }
};


TEST_CASE("NO_TEST") {}
