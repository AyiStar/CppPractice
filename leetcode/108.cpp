// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return subarrayToBST(nums, 0, nums.size()-1);
    }

private:
    TreeNode* subarrayToBST(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        if (left == right) {
            return new TreeNode(nums[left]);
        }
        int mid{(left + right) / 2};
        auto root = new TreeNode(nums[mid]);
        root->left = subarrayToBST(nums, left, mid-1);
        root->right = subarrayToBST(nums, mid+1, right);
        return root;
    }
};


TEST_CASE("NO_TEST") {}
