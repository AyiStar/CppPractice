// https://leetcode.com/problems/count-binary-substrings/
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>

class Solution {
public:
    int countBinarySubstrings(std::string s) {
        int n = s.length();
        int ret = 0;
        for (int k = 0; k < n - 1; k++) {
            if (s[k] == s[k+1]) {
                continue;
            }

            for (int i = k, j = k + 1; i >= 0 && j < n; i--, j++, ret++) {
                if (s[i] != s[k] || s[j] != s[k+1]) {
                    break;
                }
            }
        }
        return ret;
    }
};


TEST_CASE("EXAMPLE") {
    auto ret1 = Solution().countBinarySubstrings("00110011");
    REQUIRE(ret1 == 6);

    auto ret2 = Solution().countBinarySubstrings("00110011");
    REQUIRE(ret2 == 4);
}