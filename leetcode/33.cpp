// https://leetcode.com/problems/search-in-rotated-sorted-array

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;

        // search the real start index
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int start_index = left;

        // perform binary search
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int index = (mid + start_index) % n;
            int x = nums[index];
            if (x < target) {
                left = mid + 1;
            } else if (x > target) {
                right = mid - 1;
            } else {
                return index;
            }
        }
        return -1;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{4,5,6,7,0,1,2};
    REQUIRE(Solution().search(nums, 0) == 4);
}