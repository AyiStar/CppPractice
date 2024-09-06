// https://leetcode.com/problems/partition-equal-subset-sum

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        if (total % 2) {
            return false;
        } else if (total == 0) {
            return true;
        }
        int target = total / 2;
        
        memo = std::vector<std::vector<int>>(n + 1, std::vector<int>(target + 1, -1));
        memo[0] = std::vector<int>(target + 1, 0);
        memo[0][0] = 1;
        return dp(n, target, nums);
    }

private:
    std::vector<std::vector<int>> memo;
    bool dp(int n, int target, const std::vector<int>& nums) {
        if (memo[n][target] >= 0) {
            return memo[n][target];
        }
        int num = nums[n - 1];
        bool ret = dp(n-1, target, nums);
        if (target >= num) {
            ret |= dp(n-1, target - num, nums);
        }
        memo[n][target] = ret;
        return ret;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> input{1,5,11,5};
    REQUIRE(Solution().canPartition(input) == true);
}