// https://leetcode.com/problems/find-all-anagrams-in-a-string

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>


class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        int np = p.length(), ns = s.length();
        if (ns < np) {
            return {};
        }

        // init pattern
        int pattern_vec[26]{0};
        for (char c: p) {
            pattern_vec[c - 'a']++;
        }

        // init window
        int window_vec[26]{0};
        for (int i = 0; i < np; i++) {
            window_vec[s[i] - 'a']++;
        }

        // sliding
        std::vector<int> ret;
        auto window_matched = [&]() -> bool {
            for (int k = 0; k < 26; k++) {
                if (window_vec[k] != pattern_vec[k]) {
                    return false;
                }
            }
            return true;
        };
        if (window_matched()) {
            ret.push_back(0);
        }
        for (int i = 1; i + np <= ns; i++) {
            window_vec[s[i-1] - 'a']--;
            window_vec[s[i+np-1] - 'a']++;
            if (window_matched()) {
                ret.push_back(i);
            }
        }
        return ret;

    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().findAnagrams("abab", "ab") == std::vector<int>{0, 1, 2});
}