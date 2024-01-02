// https://leetcode.com/problems/minimum-path-sum/
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        std::size_t m{grid.size()}, n{grid[0].size()};
        std::vector<int> dp{grid[0]};
        for (std::size_t i = 1; i < n; i++) {
            dp[i] += dp[i-1];
        }
        for (std::size_t i = 1; i < m; i++) {
            dp[0] = dp[0] + grid[i][0];
            for (std::size_t j = 1; j < n; j++) {
                dp[j] = std::min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
        return dp[n-1];
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> grid{
        {1,3,1}, {1,5,1}, {4,2,1}
    };
    REQUIRE(Solution().minPathSum(grid) == 7);
}