// https://leetcode.com/problems/sliding-window-maximum/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <set>
#include <queue>


class Solution {
public:

    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::deque<int> window;
        std::vector<int> window_max_list;
        std::size_t w_left{0}, w_right{0};
        for(; w_right < nums.size(); w_right++) {
            while (!window.empty() && window.back() < nums[w_right]) {
                window.pop_back();
            }
            window.push_back(nums[w_right]);
            if (w_right - w_left == static_cast<std::size_t>(k - 1)) {
                window_max_list.push_back(window.front());
                if (window.front() == nums[w_left]) {
                    window.pop_front();
                }
                w_left++;
            }
        }
        return window_max_list;
    }

    std::vector<int> maxSlidingWindow_with_multiset_N_LOGN(const std::vector<int>& nums, int k) {
        std::vector<int> window_max_list;
        std::multiset<int> window{nums.begin(), nums.begin() + std::min(k, static_cast<int>(nums.size()))};
        if (window.size() == static_cast<std::size_t>(k)) {
            window_max_list.push_back(*window.rbegin());
        }
        for (std::size_t i = k; i < nums.size(); i++) {
            window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
            window_max_list.push_back(*window.rbegin());
        }
        return window_max_list;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1,3,-1,-3,5,3,6,7};
    std::vector<int> ans{3,3,5,5,6,7};
    REQUIRE(Solution().maxSlidingWindow(nums, 3) == ans);
}

TEST_CASE("BAD CASE") {
    std::vector<int> nums{7, 2, 4};
    std::vector<int> ans{7, 4};
    REQUIRE(Solution().maxSlidingWindow(nums, 2) == ans);
}