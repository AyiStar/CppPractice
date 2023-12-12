// https://leetcode.com/problems/longest-consecutive-sequence
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <unordered_set>


class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> num_set{nums.begin(), nums.end()};
        int max_cons_count{0};
        for (const auto& num: num_set) {
            if (num_set.find(num - 1) == num_set.end()) {
                int count{0};
                for (auto cons{num}; num_set.find(cons) != num_set.end(); cons++) {
                    count++;
                }
                max_cons_count = std::max(max_cons_count, count);
            }
        }
        return max_cons_count;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{100,4,200,1,3,2};
    REQUIRE(Solution().longestConsecutive(nums) == 4);
}