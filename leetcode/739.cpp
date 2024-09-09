// https://leetcode.com/problems/daily-temperatures

#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n, 0);
        std::vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[stk.back()] < temperatures[i]) {
                result[stk.back()] = i - stk.back();
                stk.pop_back();
            }
            stk.push_back(i);
        }
        return result;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> temp{73,74,75,71,69,72,76,73};
    REQUIRE(Solution().dailyTemperatures(temp) == std::vector<int>{1,1,4,2,1,1,0,0});
}