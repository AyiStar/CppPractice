// https://leetcode.com/problems/minimum-falling-path-sum

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        dp[0] = matrix[0];
        // i-th row
        for (int i = 1; i < n; i++) {
            // j-th col
            for (int j = 0; j < n; j++) {
                int min = dp[i-1][j];
                if (j - 1 >= 0) {
                    min = std::min(min, dp[i-1][j-1]);
                }
                if (j + 1 < n) {
                    min = std::min(min, dp[i-1][j+1]);
                }
                dp[i][j] = min + matrix[i][j];
            }
        }
        return *std::min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> matrix {{2,1,3}, {6,5,4}, {7,8,9}};
    REQUIRE(Solution().minFallingPathSum(matrix) == 13);
}