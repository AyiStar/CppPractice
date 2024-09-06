// https://leetcode.com/problems/edit-distance
#include <catch2/catch_test_macros.hpp>
#include <string>


class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n2; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = std::min(
                        dp[i][j-1],
                        std::min(
                            dp[i-1][j],
                            dp[i-1][j-1]
                        )
                    ) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};

TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().minDistance("horse", "ros") == 3);
}