// https://leetcode.com/problems/subarray-sum-equals-k/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <unordered_map>


class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_occur_map{{0, 1}};
        int curr_prefix = 0;
        int ans = 0;
        for (const auto num: nums) {
            curr_prefix += num;
            if (prefix_occur_map.find(curr_prefix - k) != prefix_occur_map.end()) {
                ans += prefix_occur_map[curr_prefix - k];
            }
            if (prefix_occur_map.find(curr_prefix) != prefix_occur_map.end()) {
                prefix_occur_map[curr_prefix]++;
            } else {
                prefix_occur_map[curr_prefix] = 1;
            }
        }
        return ans;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1, 2, 3, 4, 5};
    REQUIRE(Solution().subarraySum(nums, 3) == 2);
    REQUIRE(Solution().subarraySum(nums, 9) == 2);
}