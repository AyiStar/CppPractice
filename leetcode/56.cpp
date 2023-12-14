// https://leetcode.com/problems/merge-intervals
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>
#include <algorithm>


class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        // assume intervals.size() > 1
        std::vector<std::vector<int>> merged_intervals;
        std::sort(intervals.begin(), intervals.end(),
            [](const std::vector<int>& a, const std::vector<int>& b) {return a[0] < b[0];} );
        
        std::vector<int> curr_interval{intervals[0]};
        for (std::size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= curr_interval[1]) {
                curr_interval[1] = std::max(intervals[i][1], curr_interval[1]);
            } else {
                merged_intervals.push_back(curr_interval);
                curr_interval = intervals[i];
            }
        }
        merged_intervals.push_back(curr_interval);

        return merged_intervals;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> sol{{1,6}, {8,10}, {15,18}};
    REQUIRE_THAT(Solution().merge(intervals), Catch::Matchers::UnorderedEquals(sol));
}

TEST_CASE("BAD_CASE") {
    std::vector<std::vector<int>> intervals{{1,4},{2,3}};
    std::vector<std::vector<int>> sol{{1,4}};
    REQUIRE_THAT(Solution().merge(intervals), Catch::Matchers::UnorderedEquals(sol));
}