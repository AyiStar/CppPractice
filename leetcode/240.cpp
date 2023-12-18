// https://leetcode.com/problems/search-a-2d-matrix-ii
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>


class Solution {
public:

    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
            if (searchRow(row, target)) {
                return true;
            }
        }
        return false;
    }

    bool searchRow(const std::vector<int>& row, int target) {
        int left{0}, right{static_cast<int>(row.size())-1};
        while (left <= right) {
            auto mid = (left + right) / 2;
            if (row[mid] == target) {
                return true;
            } else if (row[mid] < target) {
                left = mid + 1;
            } else if (row[mid] > target) {
                right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrixDivideConquer(std::vector<std::vector<int>>& matrix, int target) {
        return searchSubMatrix(matrix, target, 0, matrix.size()-1, 0, matrix[0].size()-1);
    }

    bool searchSubMatrix(const std::vector<std::vector<int>>& matrix, int target, int row_left, int row_right, int col_left, int col_right) {
        if (row_left == row_right && col_left == col_right) {
            return (matrix[row_left][col_left] == target);
        }
        if (row_left > row_right || col_left > col_right) {
            return false;
        }
        int row_mid = (row_left + row_right) / 2;
        int col_mid = (col_left + col_right) / 2;
        int elem = matrix[row_mid][col_mid];
        if (elem == target) {
            return true;
        } else if (elem > target) {
            return searchSubMatrix(matrix, target, row_left, row_mid, col_left, col_mid-1) ||
                   searchSubMatrix(matrix, target, row_left, row_mid-1, col_mid, col_right) ||
                   searchSubMatrix(matrix, target, row_mid+1, row_right, col_left, col_mid-1);
        } else {
            return searchSubMatrix(matrix, target, row_left, row_mid, col_mid+1, col_right) ||
                   searchSubMatrix(matrix, target, row_mid+1, row_right, col_left, col_mid) ||
                   searchSubMatrix(matrix, target, row_mid+1, row_right, col_mid+1, col_right);
        }
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> matrix {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};
    REQUIRE(Solution().searchMatrix(matrix, 5) == true);
    REQUIRE(Solution().searchMatrix(matrix, 100) == false);
}