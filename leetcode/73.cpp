// https://leetcode.com/problems/set-matrix-zeroes
#include <catch2/catch_test_macros.hpp>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::size_t m{matrix.size()}, n{matrix[0].size()};
        bool row0{false}, col0{false};
        for (std::size_t i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        for (std::size_t j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        for (std::size_t i = 1; i < m; i++) {
            for (std::size_t j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (std::size_t i = 1; i < m; i++) {
            for (std::size_t j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0) {
            for (std::size_t j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0) {
            for (std::size_t i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
    Solution().setZeroes(matrix);
    std::vector<std::vector<int>> solution{{1,0,1},{0,0,0},{1,0,1}};
    REQUIRE(matrix == solution);
}

TEST_CASE("EXAMPLE2") {
    std::vector<std::vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution().setZeroes(matrix);
    std::vector<std::vector<int>> solution{{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    REQUIRE(matrix == solution);
}