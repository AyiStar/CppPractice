// https://leetcode.com/problems/perfect-squares

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <limits>


class Solution {
public:
    int numSquares(int n) {
        std::vector<int> cand;
        for(int i = 1; ; i++) {
            int sq = i * i;
            if (sq > n) {
                break;
            }
            cand.push_back(sq);
        }
        std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int sq: cand) {
                if (sq > i) {
                    break;
                }
                dp[i] = std::min(dp[i], dp[i-sq]);
            }
            dp[i]++;
        }
        return dp[n];
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().numSquares(12) == 3);
    REQUIRE(Solution().numSquares(13) == 2);
}