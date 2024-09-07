// https://leetcode.com/problems/single-number

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ret = 0;
        for (int n: nums) {
            ret = ret ^ n;
        }
        return ret;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{4, 1, 2, 1, 2};
    REQUIRE(Solution().singleNumber(nums) == 4);
}