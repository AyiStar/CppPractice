// https://leetcode.com/problems/longest-common-subsequence

#include <catch2/catch_test_macros.hpp>
#include <string>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char c1{text1.at(i-1)}, c2{text2.at(j-1)};
                if (c1 == c2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = std::max(dp[i][j], dp[i-i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().longestCommonSubsequence("abcde", "ace") == 3);
    REQUIRE(Solution().longestCommonSubsequence("abc", "abc") == 3);
    REQUIRE(Solution().longestCommonSubsequence("abc", "def") == 0);
}