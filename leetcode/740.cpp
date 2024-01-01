// https://leetcode.com/problems/delete-and-earn/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <limits>
#include <algorithm>


class Solution {
public:
    int deleteAndEarn(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> values;
        std::vector<int> counts;
        int n = nums.size();
        int i = 0, j = -1, val = std::numeric_limits<int>::max();
        while (i < n) {
            if (nums[i] != val) {
                val = nums[i];
                values.push_back(val);
                counts.push_back(1);
                j++;
            } else {
                counts[j]++;
            }
            i++;
        }
        int m = values.size();
        std::vector<int> dp(m, 0);
        // dp[0] = values[0] * counts[0];
        // if values[i] - values[i-1] > 1
        // dp[i] = dp[i-1] + values[i] * counts[i]
        // else
        // dp[i] = max(dp[i-1], dp[i-2] + values * counts[i])
        dp[0] = values[0] * counts[0];
        for (int i = 1; i < m; i++) {
            if (values[i] - values[i-1] > 1) {
                dp[i] = dp[i-1] + values[i] * counts[i];
            } else if (i == 1) {
                dp[i] = std::max(dp[i-1], values[i] * counts[i]);
            } else {
                dp[i] = std::max(dp[i-1], dp[i-2] + values[i] * counts[i]);
            }
        }
        return dp[m-1];
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> input1{3, 4, 2};
    REQUIRE(Solution().deleteAndEarn(input1)== 6);

    std::vector<int> input2{2, 2, 3, 3, 3, 4};
    REQUIRE(Solution().deleteAndEarn(input2)== 9);
}
