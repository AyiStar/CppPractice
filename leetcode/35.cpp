// https://leetcode.com/problems/search-insert-position

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1,3,5,6};
    REQUIRE(Solution().searchInsert(nums, 5) == 2);
    REQUIRE(Solution().searchInsert(nums, 2) == 1);
}