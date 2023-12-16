// https://leetcode.com/problems/two-sum/
#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        size_t len = nums.size();
        std::vector<int> result;
        for (std::size_t i = 0; i < len; i++) {
            for (std::size_t j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(static_cast<int>(i));
                    result.push_back(static_cast<int>(j));
                }
            }
        }
        return result;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> v {2, 7, 11, 15};
    REQUIRE( Solution().twoSum(v, 9) == std::vector<int> {0, 1});
}