// https://leetcode.com/problems/triangle
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>


class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        std::size_t n{triangle.size()};
        std::vector<int> dp(n, 0);
        std::vector<int> old(n, 0);
        dp[0] = triangle[0][0];
        for (std::size_t i = 1; i < n; i++) {
            std::copy(dp.begin(), dp.end(), old.begin());
            dp[0] = old[0] + triangle[i][0];
            for (std::size_t j = 1; j < i; j++) {
                dp[j] = std::min(old[j-1], old[j]) + triangle[i][j];
            }
            dp[i] = old[i-1] + triangle[i][i];
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> input{
        {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}
    };
    REQUIRE(Solution().minimumTotal(input) == 11);
}