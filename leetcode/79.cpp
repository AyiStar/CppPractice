// https://leetcode.com/problems/word-search
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <unordered_set>


class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        m_ = static_cast<int>(board.size());
        n_ = static_cast<int>(board[0].size());
        visited_ = std::vector<std::vector<char>>(m_, std::vector<char>(n_, 0));
        word_ = word;
        len_ = static_cast<int>(word.size());
        found_ = false;
        for (int i = 0; i < m_; i++) {
            for (int j = 0; j < n_; j++) {
                backtracing(i, j, 0, board);
            }
        }
        return found_;
    }

private:
    void backtracing(int i, int j, int n, const std::vector<std::vector<char>>& board) {
        if (found_ ||board[i][j] != word_[n]) {
            return;
        }
        if (n == len_ - 1) {
            found_ = true;
            return;
        }
        visited_[i][j] = 1;
        if (i - 1 >= 0 && !visited_[i-1][j]) {
            backtracing(i-1, j, n+1, board);
        }
        if (i + 1 < m_ && !visited_[i+1][j]) {
            backtracing(i+1, j, n+1, board);
        }
        if (j - 1 >= 0 && !visited_[i][j-1]) {
            backtracing(i, j-1, n+1, board);
        }
        if (j + 1 < n_ && !visited_[i][j+1]) {
            backtracing(i, j+1, n+1, board);
        }
        visited_[i][j] = 0;
    }

    static const int MAX_LEN_ = 15;
    std::string word_;
    std::vector<std::vector<char>> visited_;
    int m_;
    int n_;
    int len_;
    bool found_;
};


TEST_CASE("EXAMPLE") {
    std::vector<std::vector<char>> board{
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    REQUIRE(Solution().exist(board, "ABCCED"));
    REQUIRE(Solution().exist(board, "CESEEDFS"));
    REQUIRE(!Solution().exist(board, "ABCS"));
}
