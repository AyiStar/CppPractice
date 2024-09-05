// https://leetcode.com/problems/longest-increasing-subsequence

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j]);
                }
            }
            dp[i]++;
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};

TEST_CASE("EXAMPLE") {
    std::vector<int> nums {10,9,2,5,3,7,101,18};
    REQUIRE(Solution().lengthOfLIS(nums) == 4);
}