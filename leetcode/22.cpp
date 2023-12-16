// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
#include <stack>
#include <catch2/catch_test_macros.hpp>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::vector<char> stk;
        backTracking(2 * n, result, stk, 0);
        return result;
    }

private:
    void backTracking(const int n, std::vector<std::string> &result, std::vector<char> &stk, int status) {
        if (static_cast<int>(stk.size()) == n) {
            if (status == 0) {
                result.push_back(std::string(stk.begin(), stk.end()));
            }
            return;
        }
        // back track
        stk.push_back('(');
        backTracking(n, result, stk, status + 1);
        stk.pop_back();
        if (status > 0) {
            stk.push_back(')');
            backTracking(n, result, stk, status - 1);
            stk.pop_back();
        }
    }    

};

TEST_CASE("EXAMPLE") {
    const int n = 1;
    const std::vector<std::string> result {
        "()"
    };
    REQUIRE(Solution().generateParenthesis(n) == result);
}