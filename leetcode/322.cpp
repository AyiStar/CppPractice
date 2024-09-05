// https://leetcode.com/problems/coin-change
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <limits>


class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        constexpr int imax = std::numeric_limits<int>::max();
        std::vector<int> dp(amount + 1, imax);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int c: coins) {
                if (i - c >= 0 && dp[i - c] < imax) {
                    dp[i] = std::min(dp[i - c] + 1, dp[i]);
                }
            }
        }
        return (dp[amount] == imax) ? -1 : dp[amount];
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> coins{1, 2, 5};
    REQUIRE(Solution().coinChange(coins, 11) == 3);
}

TEST_CASE("NONE") {
    std::vector<int> coins{2};
    REQUIRE(Solution().coinChange(coins, 3) == -1);
}