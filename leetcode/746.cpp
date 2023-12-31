// https://leetcode.com/problems/min-cost-climbing-stairs
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        // assume cost.size() >= 2
        int n = cost.size();
        // dp[n] = min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2])
        // dp[0] = 0
        // dp[1] = 0
        int a = 0, b = 0;  // dp[i-2] and dp[i-1]
        for (int i = 2; i <= n; i++) {
            // calculate c == dp[i]
            int c = std::min(a+cost[i-2], b+cost[i-1]);
            a = b;
            b = c;
        }
        return b;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> input1{10, 15, 20};
    std::vector<int> input2{1,100,1,1,1,100,1,1,100,1};
    REQUIRE(Solution().minCostClimbingStairs(input1) == 15);
    REQUIRE(Solution().minCostClimbingStairs(input2) == 6);
}