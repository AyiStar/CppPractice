// https://leetcode.com/problems/rotate-array/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <numeric>


class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        std::size_t n{nums.size()};
        k = k % n;
        auto m{std::gcd(n, static_cast<std::size_t>(k))};
        auto ring_forward = [&k, &n](std::size_t x){ return (x + k) % n;};
        for (std::size_t i = 0; i < m; i++) {
            auto init{i};
            int tmp{nums[init]};
            for (auto j = ring_forward(init); j != init; j = ring_forward(j)) {
                std::swap(tmp, nums[j]);
            }
            std::swap(tmp, nums[init]);
        }
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1,2,3,4,5,6,7};

    std::vector<int> nums1{nums};
    Solution().rotate(nums1, 1);
    REQUIRE(nums1 == std::vector<int>{7,1,2,3,4,5,6});

    std::vector<int> nums2{nums};
    Solution().rotate(nums2, 3);
    REQUIRE(nums2 == std::vector<int>{5,6,7,1,2,3,4});
}