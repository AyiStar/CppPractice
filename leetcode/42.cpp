// https://leetcode.com/problems/trapping-rain-water
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int trap(std::vector<int>& height) {
        int trapped_water{0}, left_max{0}, right_max{0};
        std::size_t left{0}, right{height.size() - 1};
        while (left < right) {
            left_max = std::max(left_max, height[left]);
            right_max = std::max(right_max, height[right]);
            if (left_max <= right_max) {
                trapped_water += left_max - height[left];
                left++;
            } else {
                trapped_water += right_max - height[right];
                right--;
            }
        }
        return trapped_water;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    REQUIRE(Solution().trap(height) == 6);
}