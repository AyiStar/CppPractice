// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums {3,4,5,1,2};
    REQUIRE(Solution().findMin(nums) == 1);
}