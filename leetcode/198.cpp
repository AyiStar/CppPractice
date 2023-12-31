// https://leetcode.com/problems/house-robber/
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int rob(std::vector<int>& nums) {
        // dp[n] = max(dp[n-2]+nums[n], dp[n-1])
        // dp[0] = nums[0]
        // dp[1] = max(nums[0], nums[1])
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return std::max(nums[0], nums[1]);
        }
        int a = nums[0], b = std::max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            int tmp = std::max(a + nums[i], b);
            a = b;
            b = tmp;
        }
        return b;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> input1{1, 2, 3, 1};
    std::vector<int> input2{2, 7, 9, 3, 1};
    REQUIRE(Solution().rob(input1) == 4);
    REQUIRE(Solution().rob(input2) == 12);
}