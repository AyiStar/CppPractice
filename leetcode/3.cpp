// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, std::size_t> hash_table;
        std::size_t i = 0, j = 0, max_sub_len = 0, len = s.size();
        while (true) {
            if (j >= len) {
                max_sub_len = std::max(j - i, max_sub_len);
                break;
            }
            if (auto it = hash_table.find(s.at(j)); it != hash_table.end()) {
                max_sub_len = std::max(j - i, max_sub_len);
                auto old_i = i;
                i = it->second + 1;
                for (int k = old_i; k < i; k++) {
                    hash_table.erase(s.at(k));
                }
            }
            hash_table[s.at(j)] = j;
            j++;
        }
        return max_sub_len;
    }
};


TEST_CASE("EXAMPLE") {
    std::string s{"abcabcbb"};
    REQUIRE( Solution().lengthOfLongestSubstring(s) == 3);
}