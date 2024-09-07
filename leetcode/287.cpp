// https://leetcode.com/problems/find-the-duplicate-number

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) {
                break;
            }
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{3, 1, 3, 4, 2};
    REQUIRE(Solution().findDuplicate(nums) == 3);
}