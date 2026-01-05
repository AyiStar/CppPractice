// https://leetcode.com/problems/isomorphic-strings
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
    public:
        bool isIsomorphic(std::string s, std::string t) {
            std::unordered_map<char, char> chMap;
            std::unordered_set<char> mappedSet;
            if (s.length() != t.length()) {
                return false;
            }
            auto n = s.length();
            for(int i = 0; i < n; i++) {
                char a{s.at(i)}, b{t.at(i)};
                if (chMap.find(a) == chMap.end()) {
                    chMap[a] = b;
                    if (mappedSet.find(b) != mappedSet.end()) {
                        return false;
                    }
                    mappedSet.insert(b);
                } else if (chMap[a] != b) {
                    return false;
                }
            }
            return true;
        }
};


TEST_CASE("EXAMPLE") {
    auto ret1 = Solution().isIsomorphic("egg", "add");
    REQUIRE(ret1);

    auto ret2 = Solution().isIsomorphic("paper", "title");
    REQUIRE(ret2);
}