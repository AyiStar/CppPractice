// https://leetcode.com/problems/rotate-image
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        // assume square matrix
        int n = matrix.size();
        int b{0}, e{n-1};
        while (b < e) {
            for (int i = 0; i < e - b; i++) {
                // [b, b+i] -> [b+i, e] -> [e, e-i] -> [e-i, b]
                int tmp{matrix[e-i][b]};
                matrix[e-i][b] = matrix[e][e-i];
                matrix[e][e-i] = matrix[b+i][e];
                matrix[b+i][e] = matrix[b][b+i];
                matrix[b][b+i] = tmp;
            }
            b++;
            e--;
        }
    }
};


TEST_CASE("BAD_CASE") {
    std::vector<std::vector<int>> matrix{{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},
        {33,1,20,7,21,7},{4,24,1,6,32,34}};
    Solution().rotate(matrix);
    std::vector<std::vector<int>> ans{{4,33,13,32,12,2},{24,1,14,33,27,29},{1,20,32,32,9,20},
        {6,7,27,2,25,26},{32,21,22,28,13,16},{34,7,26,14,21,28}};
    REQUIRE(matrix == ans);
}

TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution().rotate(matrix);
    std::vector<std::vector<int>> ans{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    REQUIRE(matrix == ans);
}