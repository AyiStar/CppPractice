// https://leetcode.com/problems/palindromic-substrings
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int n = s.length();
        int ret{0};
        for (int k = 0; k < n; k++) {
            int i{k}, j{k};
            // single
            for (int i = k, j = k; i >= 0 && j < n; ret++, i--, j++) {
                if (s[i] != s[j]) {
                    break;
                }
            }
            // single
            for (int i = k, j = k + 1; i >= 0 && j < n; ret++, i--, j++) {
                if (s[i] != s[j]) {
                    break;
                }
            }
        }
        return ret;
    }
};


TEST_CASE("EXAMPLE") {
    auto ret1 = Solution().countSubstrings("abc");
    REQUIRE(ret1 == 3);

    auto ret2 = Solution().countSubstrings("aaa");
    REQUIRE(ret2 == 6);
}