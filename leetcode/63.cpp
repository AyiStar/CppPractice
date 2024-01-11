// https://leetcode.com/problems/unique-paths-ii
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        std::size_t m{obstacleGrid.size()}, n{obstacleGrid[0].size()};
        std::vector<int> dp(n, 1);
        
        dp[0] = (obstacleGrid[0][0] == 1) ? 0: 1;
        for (std::size_t j = 1; j < n; j++) {
            dp[j] = (dp[j - 1] > 0 && obstacleGrid[0][j] == 0) ? 1 : 0;
        }

        for (std::size_t i = 1; i < m; i++) {
            dp[0] = (dp[0] > 0 && obstacleGrid[i][0] == 0) ? dp[0] : 0;
            for (std::size_t j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }
                dp[j] = dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    REQUIRE(Solution().uniquePathsWithObstacles(obstacleGrid) == 2);
}
