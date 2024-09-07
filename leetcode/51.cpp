// https://leetcode.com/problems/n-queens

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        N = n;
        board = std::vector<int>(N, -1);
        backtrace(0);
        return all_solutions;
    }

private:
    std::vector<std::vector<std::string>> all_solutions;
    std::vector<int> board;
    int N;


    auto trans_solution (const std::vector<int>& v) -> std::vector<std::string> {
        std::vector<std::string> ret;
        std::string pattern(N, '.');
        for (int pos: v) {
            pattern[pos] = 'Q';
            ret.push_back(pattern);
            pattern[pos] = '.';
        }
        return ret;
    }

    auto check_board (int k, int i) -> bool {
        for (int j = 0; j < k; j++) {
            if (board[j] == i || std::abs(k - j) == std::abs(i - board[j])) {
                return false;
            }
        }
        return true;
    }

    void backtrace(int k) {
        if (k == N) {
            all_solutions.push_back(trans_solution(board));
            return;
        }
        for (int i = 0; i < N; i++) {
            if (!check_board(k, i)) {
                continue;
            }
            board[k] = i;
            backtrace(k + 1);
        }

    };

};