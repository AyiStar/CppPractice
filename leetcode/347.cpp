// https://leetcode.com/problems/top-k-frequent-elements

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>


class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::map<int, int> counter;
        for (int n: nums) {
            counter[n]++;
        }
        auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second < b.second;
        };
        std::vector<std::pair<int, int>> heap{counter.begin(), counter.end()};
        std::make_heap(heap.begin(), heap.end(), comp);
        std::vector<int> ret;
        for (int i = 0; i < k; i++) {
            std::pop_heap(heap.begin(), heap.end(), comp);
            ret.push_back(heap.back().first);
            heap.pop_back();
        }
        return ret;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{1,1,1,2,2,3};
    REQUIRE(Solution().topKFrequent(nums, 2) == std::vector<int>{1, 2});
}