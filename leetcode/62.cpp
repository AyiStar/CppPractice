// https://leetcode.com/problems/unique-paths
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) {
            std::swap(m, n);
        }
        std::vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().uniquePaths(3, 7) == 28);
    REQUIRE(Solution().uniquePaths(3, 2) == 3);
}