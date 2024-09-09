// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
             return {-1, -1};
        }
        
        // find one index
        int left = 0, right = n-1;
        int found_index = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                found_index = mid;
                break;
            }
        }
        if (found_index < 0) {
            return {-1, -1};
        }

        // find the first element less than target
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int left_bound = left;
        
        // find the first element larger than target
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int right_bound = right;
        return {left_bound, right_bound};
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{5,7,7,8,8,10};
    REQUIRE(Solution().searchRange(nums, 8) == std::vector<int>{3, 4});
    REQUIRE(Solution().searchRange(nums, 6) == std::vector<int>{-1, -1});
    nums = {2, 2};
    REQUIRE(Solution().searchRange(nums, 2) == std::vector<int>{0, 1});
}

TEST_CASE("CORNER") {
    std::vector<int> nums;
    REQUIRE(Solution().searchRange(nums, 1) == std::vector<int>{-1, -1});
    nums.push_back(1);
    REQUIRE(Solution().searchRange(nums, 1) == std::vector<int>{0, 0});
}