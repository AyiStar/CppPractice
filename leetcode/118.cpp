// https://leetcode.com/problems/pascals-triangle

#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret(numRows);
        for (int i = 0; i < numRows; i++) {
            ret[i] = std::vector<int>(i + 1, 1);
        }
        for (int i = 1; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
            }
        }
        return ret;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> sol {
        {1},
        {1,1},
        {1,2,1},
        {1,3,3,1},
        {1,4,6,4,1}
    };
    REQUIRE(Solution().generate(5) == sol);
}