// https://leetcode.com/problems/longest-palindrome/
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
        int counter[52];
        int ret = 0;
        for (char c: s) {
            if (c >= 'a' && c <= 'z')
                counter[c - 'a'] += 1;
            else
                counter[c - 'A' + 26] += 1;
        }
        int extra = 0;
        for (int i = 0; i < 52; i++) {
            ret += (counter[i] / 2) * 2;
            extra = extra | (counter[i] % 2);
        }
        return ret + extra;
    }
};

TEST_CASE("EXAMPLE") {
    auto ret1 = Solution().longestPalindrome("abccccdd");
    REQUIRE(ret1 == 7);

    auto ret2 = Solution().longestPalindrome("a");
    REQUIRE(ret2 == 1);
}