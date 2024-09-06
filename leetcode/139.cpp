// https://leetcode.com/problems/word-break

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_map<char, std::vector<size_t>> map;
        for (size_t i = 0; i < wordDict.size(); i++) {
            const auto& w = wordDict[i];
            map[w.at(w.length() - 1)].push_back(i);
        }

        int n = s.length();
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (map.find(s[i-1]) == map.end()) {
                continue;
            }
            for (int j: map.at(s[i-1])) {
                const auto& w = wordDict[j];
                int m = w.length();
                if (m <= i && s.substr(i - m, m) == w) {
                    dp[i] = dp[i] | dp[i - m];
                }
            }
        }
        return static_cast<bool>(dp[n]);
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::string> wordDict{"apple", "pen"};
    REQUIRE(Solution().wordBreak("applepenapple", wordDict) == true);
}