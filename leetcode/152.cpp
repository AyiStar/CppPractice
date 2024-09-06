// https://leetcode.com/problems/maximum-product-subarray

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <limits>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int max_prod = std::numeric_limits<int>::min();
        int prod = 1;
        for (int n: nums) {
            prod *= n;
            max_prod = std::max(max_prod, prod);
            if (prod == 0) {
                prod = 1;
            }
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prod *= nums[i];
            max_prod = std::max(max_prod, prod);
            if (prod == 0) {
                prod = 1;
            }
        }
        return max_prod;
    }
};


TEST_CASE("EXAMPLE") {
    auto nums = std::vector<int>{2,3,-2,4};
    REQUIRE(Solution().maxProduct(nums) == 6);
}