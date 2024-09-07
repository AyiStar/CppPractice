// https://leetcode.com/problems/next-permutation

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int change_index = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                change_index = i-1;
                break;
            }
        }
        if (change_index >= 0) {
            for (int i = n - 1; i > change_index; i--) {
                if (nums[i] > nums[change_index]) {
                    std::swap(nums[i], nums[change_index]);
                    break;
                }
            }
        }

        for (int i = change_index + 1, j = n - 1; i < j; i++, j--) {
            std::swap(nums[i], nums[j]);
        }
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1, 1, 5};
    Solution().nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{1, 5, 1});
}

TEST_CASE("BADCASE") {
    std::vector<int> nums{3, 2, 1};
    Solution().nextPermutation(nums);
    REQUIRE(nums == std::vector<int>{1, 2, 3});
}