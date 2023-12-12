// https://leetcode.cn/problems/minimum-window-substring
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <limits>


class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        std::vector<int> windows_map(std::numeric_limits<std::string::value_type>::max(), 0);
        for (const auto& c: t) {
            windows_map[c]++;
        }

        std::size_t window_left{0}, window_right{0}, counter{t.size()};
        std::size_t min_begin{0}, min_len{std::numeric_limits<std::size_t>::max()};

        while (window_right < s.size()) {
            if (windows_map[s[window_right]] > 0) {
                counter--;
            }
            windows_map[s[window_right]]--;
            window_right++;
            while (counter == 0) {
                if (window_right - window_left < min_len) {
                    min_len = window_right - window_left;
                    min_begin = window_left;
                }
                windows_map[s[window_left]]++;
                if (windows_map[s[window_left]] > 0) {
                    counter++;
                }
                window_left++;
            }
        }

        return (min_len == std::numeric_limits<std::size_t>::max()) ? "": s.substr(min_begin, min_len);
    }
};


TEST_CASE("EXAMPLE") {
    std::string s{"ADOBECODEBANC"}, t{"ABC"};
    REQUIRE(Solution().minWindow(s, t) == std::string{"BANC"});
}