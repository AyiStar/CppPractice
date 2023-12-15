// https://leetcode.com/problems/product-of-array-except-self
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> output(nums.size(), 1);
        // now output serves as prefix product array
        for (std::size_t i = 1; i < nums.size(); i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }
        int suffix_product = 1;
        for (std::size_t i = nums.size(); i--> 0;) {
            output[i] *= suffix_product;
            suffix_product *= nums[i];
        }
        return output;
    }
};


TEST_CASE("EXAMPLE1") {
    std::vector<int> nums{1,2,3,4};
    std::vector<int> ans{24,12,8,6};
    REQUIRE(Solution().productExceptSelf(nums) == ans);
}

TEST_CASE("EXAMPLE2") {
    std::vector<int> nums{-1,1,0,-3,3};
    std::vector<int> ans{0,0,9,0,0};
    REQUIRE(Solution().productExceptSelf(nums) == ans);
}