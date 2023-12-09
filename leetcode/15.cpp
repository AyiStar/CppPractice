// https://leetcode.com/problems/3sum
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        
        std::sort(nums.begin(), nums.end());
        std::size_t pivot = 0;
        while (pivot < nums.size()- 2 && nums[pivot] <= 0) {
            auto left{pivot + 1}, right{nums.size() - 1};
            while (left < right) {
                if (auto sum = nums[pivot] + nums[left] + nums[right]; sum == 0) {
                    results.push_back(std::vector{nums[pivot], nums[left], nums[right]});
                    while (left < right && nums[left+1] == nums[left]) {
                        left++;
                    }
                    while (left < right && nums[right-1] == nums[right]) {
                        right--;
                    }
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
                }
            }
            while (pivot < nums.size() - 2 && nums[pivot+1] == nums[pivot]) {
                pivot++;
            }
            pivot++;
        }
        return results; 
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> ret{{-1, -1, 2}, {-1, 0, 1}};
    REQUIRE(Solution().threeSum(nums) == ret);
}