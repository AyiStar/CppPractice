// https://leetcode.com/problems/maximum-subarray
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <limits>


class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // assume nums.size() > 0
        if (nums.size() == 1) {
            return nums[0];
        }        
        int curr_presum{0}, min_presum{0}, max_subsum{std::numeric_limits<int>::min()};
        for (const auto& num: nums) {
            curr_presum += num;
            max_subsum = std::max(max_subsum, curr_presum - min_presum);
            min_presum = std::min(min_presum, curr_presum);
        }
        return max_subsum;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    REQUIRE(Solution().maxSubArray(nums) == 6);
}

TEST_CASE("EXAMPLE2") {
    std::vector<int> nums{5,4,-1,7,8};
    REQUIRE(Solution().maxSubArray(nums) == 23);
}

TEST_CASE("EXAMPLE3") {
    std::vector<int> nums{-2, -1};
    REQUIRE(Solution().maxSubArray(nums) == -1);
}

TEST_CASE("EXTREME") {
    std::vector<int> nums{1};
    REQUIRE(Solution().maxSubArray(nums) == 1);
}