// https://leetcode.com/problems/container-with-most-water
#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        std::size_t left{0}, right{height.size() - 1};
        int max_area = 0;
        while (left < right) {
            int curr_area{0};
            if (height[left] <= height[right]) {
                curr_area = height[left] * static_cast<int>(right - left);
                left++;
            } else {
                curr_area = height[right] * static_cast<int>(right - left);
                right--;
            }
            max_area = std::max(max_area, curr_area);
        }
        return max_area;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    REQUIRE( Solution().maxArea(height) == 49);
}