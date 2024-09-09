// https://leetcode.com/problems/search-a-2d-matrix

#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i, j;
            to2D(i, j, mid, n);
            int x = matrix[i][j];
            if (x < target) {
                left = mid + 1;
            } else if (x > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

private:
    inline void to1D(int& out, int x, int y, int n) {
        out = x * n + y;
    }

    inline void to2D(int& out_x, int& out_y, int X, int n) {
        out_x = static_cast<int>(X / n);
        out_y = X - (out_x * n);
    }

};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> m{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    REQUIRE(Solution().searchMatrix(m, 3));
    REQUIRE(!Solution().searchMatrix(m, 13));
}