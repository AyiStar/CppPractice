// https://leetcode.com/problems/rotting-oranges
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m{static_cast<int>(grid.size())}, n{static_cast<int>(grid[0].size())};
        std::queue<std::tuple<int, int, int>> queue;
        int num_fresh{0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto x = grid[i][j];
                if (x == 1) {
                    num_fresh++;
                } else if (x == 2) {
                    grid[i][j] = 1;
                    num_fresh++;
                    queue.push({i, j, 0});
                }
            }
        }
        
        int current_minute{0};
        while (!queue.empty()) {
            auto [i, j, minute] = queue.front();
            queue.pop();
            if (grid[i][j] == 2) {
                continue;
            }
            grid[i][j] = 2;
            num_fresh--;
            current_minute = minute;
            if (i-1 >= 0 && grid[i-1][j] == 1) {
                queue.push({i-1, j, minute + 1});
            }
            if (j-1 >= 0 && grid[i][j-1] == 1) {
                queue.push({i, j-1, minute + 1});
            }
            if (i+1 < m && grid[i+1][j] == 1) {
                queue.push({i+1, j, minute + 1});
            }
            if (j+1 < n && grid[i][j+1] == 1) {
                queue.push({i, j+1, minute + 1});
            }
            
        }
        if (num_fresh > 0) {
            return -1;
        }
        return current_minute;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<int>> grid1{
        {2, 1, 1}, {1, 1, 0}, {0, 1, 1}
    };
    REQUIRE(Solution().orangesRotting(grid1) == 4);

    std::vector<std::vector<int>> grid2{
        {2, 1, 1}, {0, 1, 1}, {1, 0, 1}
    };
    REQUIRE(Solution().orangesRotting(grid2) == -1);

    std::vector<std::vector<int>> grid3{
        {0, 2}
    };
    REQUIRE(Solution().orangesRotting(grid3) == 0);
}