// https://leetcode.com/problems/first-missing-positive/
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        std::size_t n = nums.size();
        for (std::size_t i = 0; i < n; i++) {
            while (true) {
                int k = nums[i];
                if (k <= 0 || static_cast<std::size_t>(k) > n) {
                    break;
                }
                if (nums[k-1] == k) {
                    break;
                }
                std::swap(nums[k-1], nums[i]);
            }
        }
        for (std::size_t i = 1; i <= n; i++) {
            if (nums[i-1] != static_cast<int>(i)) {
                return i;
            }
        }
        return n+1;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1,2,0};
    REQUIRE(Solution().firstMissingPositive(nums) == 3);
}