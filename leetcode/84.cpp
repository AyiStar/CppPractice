// https://leetcode.com/problems/largest-rectangle-in-histogram

#include <catch2/catch_test_macros.hpp>


class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        std::vector<int> left_most(n, 0), right_most(n, n - 1);
        std::vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.back()] > heights[i]) {
                right_most[stk.back()] = i - 1;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.back()] > heights[i]) {
                left_most[stk.back()] = i + 1;
                stk.pop_back();
            }
            stk.push_back(i);
        }

        int max_area = 0;
        for (int i = 0; i < n; i++) {
            max_area = std::max(max_area, heights[i] * (right_most[i] - left_most[i] + 1));
        }
        return max_area;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> heights{2,1,5,6,2,3};
    REQUIRE(Solution().largestRectangleArea(heights) == 10);
}