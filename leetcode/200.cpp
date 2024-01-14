// https://leetcode.com/problems/number-of-islands/
#include <catch2/catch_test_macros.hpp>
#include <vector>


class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int m{static_cast<int>(grid.size())}, n{static_cast<int>(grid[0].size())};
        std::vector<std::vector<std::int8_t>> visited(m, std::vector<std::int8_t>(n, 0));
        int num_islands{0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!static_cast<bool>(visited[i][j]) && (grid[i][j] == '1')) {
                    num_islands++;
                    visitIsland(grid, visited, i, j, m, n);
                }
            }
        }
        return num_islands;
    }

private:
    void visitIsland(const std::vector<std::vector<char>>& grid,
                     std::vector<std::vector<std::int8_t>>& visited,
                     int i, int j, int m, int n
                     ) {
        visited[i][j] = 1;
        if (grid[i][j] == '0') {
            return;
        }
        if (i - 1 >= 0 && !static_cast<bool>(visited[i-1][j])) {
            visitIsland(grid, visited, i-1, j, m, n);
        }
        if (i + 1 < m && !static_cast<bool>(visited[i+1][j])) {
            visitIsland(grid, visited, i+1, j, m, n);
        }
        if (j - 1 >= 0 && !static_cast<bool>(visited[i][j-1])) {
            visitIsland(grid, visited, i, j-1, m, n);
        }
        if (j + 1 < n && !static_cast<bool>(visited[i][j+1])) {
            visitIsland(grid, visited, i, j+1, m, n);
        }
        return;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<char>> grid{
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','1'}
    };
    REQUIRE(Solution().numIslands(grid) == 3);
}