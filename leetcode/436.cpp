// https://leetcode.com/problems/path-sum-iii/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <set>


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
    int pathSum(TreeNode* root, int targetSum) {
        std::vector<long long> presum_array{0};
        std::multiset<long long> presum_set{0};
        int n = 0;
        pathSumHelper(root, targetSum, n, presum_array, presum_set);
        return n;
    }

private:
    void pathSumHelper(TreeNode* root, int targetSum, int &n,
                    std::vector<long long> &presum_array,
                    std::multiset<long long> &presum_set) {
        if (root == nullptr) {
            return;
        }
        int val = root->val;
        long long presum = val + presum_array.back();
        long long target = presum - targetSum;
        n += presum_set.count(target);
        
        presum_set.insert(presum);
        presum_array.push_back(presum);
        pathSumHelper(root->left, targetSum, n, presum_array, presum_set);
        pathSumHelper(root->right, targetSum, n, presum_array, presum_set);
        presum_array.pop_back();
        presum_set.erase(presum_set.find(presum));
        return;
    }
};


TEST_CASE("NO_TEST") {}
