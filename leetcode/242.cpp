// https://leetcode.com/problems/valid-anagram/
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool isAnagram(std::string s, std::string t) {
            if (s.length() != t.length()) {
                return false;
            }
            std::unordered_map<char, int> sChMap;
            for (const char &c: s) {
                sChMap[c] += 1;
            }
            for (const char &c: t) {
                if (sChMap.find(c) == sChMap.end()) {
                    return false;
                }
                sChMap[c] -= 1;
                if (sChMap[c] < 0) {
                    return false;
                }
            }
            return true;

        }
    };

TEST_CASE("EXAMPLE") {
    auto ret1 = Solution().isAnagram("anagram", "nagaram");
    REQUIRE(ret1);

    auto ret2 = Solution().isAnagram("rat", "car");
    REQUIRE(!ret2);
}