// https://leetcode.com/problems/jump-game

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int max_reachable = 0;
        int i = 0;
        while (i < std::min(max_reachable + 1, n)) {
            max_reachable = std::max(max_reachable, i + nums[i]);
            i++;
        }
        return (max_reachable >= n - 1);
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{2,3,1,1,4};
    REQUIRE(Solution().canJump(nums) == true);
}