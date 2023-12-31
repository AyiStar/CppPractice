// https://leetcode.com/problems/climbing-stairs
#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        // assume n >= 1
        std::vector<int> dp(n + 1, 0);
        // dp[n] = dp[n-1] + dp[n-2]
        // dp[0] = 1, dp[1] = 1
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().climbStairs(2) == 2);
    REQUIRE(Solution().climbStairs(3) == 3);
}