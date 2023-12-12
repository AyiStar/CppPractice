// https://leetcode.com/problems/group-anagrams
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> grouped_strs;
        for (const auto& s: strs) {
            std::string word{s};
            std::sort(word.begin(), word.end());
            if (auto it = grouped_strs.find(word); it != grouped_strs.end()) {
                it->second.push_back(s);
            } else {
                grouped_strs.insert({word, {s}});
            }
        }
        std::vector<std::vector<std::string>> results;
        for (const auto& kv: grouped_strs) {
            results.emplace_back(std::move(kv.second));
        }
        return results;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::string> strs{"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> ans{{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}};
    REQUIRE_THAT(Solution().groupAnagrams(strs), Catch::Matchers::UnorderedEquals(ans));
}