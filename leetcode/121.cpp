// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int min_past = prices[0];
        int max_profit = 0;
        for (int p: prices) {
            min_past = std::min(min_past, p);
            max_profit = std::max(max_profit, p - min_past);
        }
        return max_profit;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> prices{7,1,5,3,6,4};
    REQUIRE(Solution().maxProfit(prices) == 5);
}