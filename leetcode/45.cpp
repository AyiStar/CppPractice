// https://leetcode.com/problems/jump-game-ii

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <limits>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> reach_steps(n, std::numeric_limits<int>::max());
        reach_steps[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < std::min(i + 1 + nums[i], n); j++) {
                reach_steps[j] = std::min(reach_steps[j], reach_steps[i] + 1);
            }
        }
        return reach_steps[n-1];
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{2,3,1,1,4};
    REQUIRE(Solution().jump(nums) == 2);
}