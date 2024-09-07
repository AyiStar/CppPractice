// https://leetcode.com/problems/majority-elemen

#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int major_num{nums[0]}, major_cnt{1};
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            if (major_cnt == 0) {
                major_cnt = 1;
                major_num = num;
            } else if (num == major_num) {
                major_cnt++;
            } else {
                major_cnt--;
            }
        }
        return major_num;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{2,2,1,1,1,2,2,3,2,5,5,2,2};
    REQUIRE(Solution().majorityElement(nums) == 2);
}