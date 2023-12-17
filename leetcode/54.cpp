// https://leetcode.com/problems/spiral-matrix/
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <unordered_map>
#include <utility>


class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ret;
        std::size_t m{matrix.size()}, n{matrix[0].size()};
        
        enum class IterDirection { LEFT, RIGHT, UP, DOWN };
        static std::unordered_map<IterDirection, std::pair<int, int>> direct_step{
            {IterDirection::LEFT, {0, -1}},
            {IterDirection::RIGHT, {0, 1}},
            {IterDirection::UP, {-1, 0}},
            {IterDirection::DOWN, {1, 0}}
        };
        static std::unordered_map<IterDirection, IterDirection> direct_trans{
            {IterDirection::RIGHT, IterDirection::DOWN},
            {IterDirection::DOWN, IterDirection::LEFT},
            {IterDirection::LEFT, IterDirection::UP},
            {IterDirection::UP, IterDirection::RIGHT}
        };

        IterDirection direct{IterDirection::RIGHT};

        int i{0}, j{-1};
        while (m > 0 && n > 0) {
            auto step = direct_step.at(direct);
            if (step.first == 0) {
                for (std::size_t k = 0; k < n; k++) {
                    i += step.first;
                    j += step.second;
                    ret.push_back(matrix[i][j]);
                }
                m--;
            } else {
                for (std::size_t k = 0; k < m; k++) {
                    i += step.first;
                    j += step.second;
                    ret.push_back(matrix[i][j]);
                }
                n--;
            }
            direct = direct_trans[direct];
        }
        return ret;
    }

};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    std::vector<int> ans{1,2,3,4,8,12,11,10,9,5,6,7};
    REQUIRE(Solution().spiralOrder(matrix) == ans);
}