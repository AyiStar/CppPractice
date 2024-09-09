// https://leetcode.com/problems/kth-largest-element-in-an-array

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::vector<int> heap{nums.begin(), nums.end()};
        heap_build(heap);
        int ret;
        for (int i = 0; i < k; i++) {
            ret = heap_pop(heap);
        }
        return ret;
    }

private:

    void heapify(std::vector<int>& h, int i) {
        int n = h.size();
        while (true) {
            int left = 2 * i, right = 2 * i + 1;
            if (left >= n) {
                break;
            }
            int child_max_index = left;
            if (right < n && h[right] > h[left]) {
                child_max_index = right;
            }
            if (h[i] < h[child_max_index]) {
                std::swap(h[i], h[child_max_index]);
                i = child_max_index;
            } else {
                break;
            }
        }
    }

    void heap_build(std::vector<int>& h) {
        int n = h.size();
        for (int i = static_cast<int>(n / 2); i >= 0 ; i--) {
            heapify(h, i);
        }
    }

    int heap_pop(std::vector<int>& h) {
        int top = h[0];
        h[0] = h[h.size()-1];
        h.pop_back();
        heapify(h, 0);
        return top;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums{3,2,1,5,6,4};
    REQUIRE(Solution().findKthLargest(nums, 1) == 6);
    REQUIRE(Solution().findKthLargest(nums, 2) == 5);
}