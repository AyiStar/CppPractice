// https://leetcode.com/problems/move-zeroes
#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        size_t snowball_size{0}, len{nums.size()};
        for (std::size_t i = 0; i < len; i++) {
            if (nums[i] == 0) {
                snowball_size++;
            } else if (snowball_size > 0) {
                std::swap(nums[i], nums[i - snowball_size]);
            }
        }
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{0, 1, 0, 3, 12};
    Solution().moveZeroes(nums);
    REQUIRE(nums == std::vector<int>{1, 3, 12, 0, 0});
}