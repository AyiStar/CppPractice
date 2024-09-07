#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 0) {
                std::swap(nums[left++], nums[i++]);
            } else if (nums[i] == 2) {
                std::swap(nums[right--], nums[i]);
            } else {
                i++;
            }
        }
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{2,0,2,1,1,0};
    Solution().sortColors(nums);
    REQUIRE(nums == std::vector<int>{0, 0, 1, 1, 2, 2});
}