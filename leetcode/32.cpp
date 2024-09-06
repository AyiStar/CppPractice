// https://leetcode.com/problems/longest-valid-parentheses

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stk;
        stk.push(-1);
        int n = s.length();
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            char c = s.at(i);
            if (c == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    max_len = std::max(max_len, i - stk.top());
                }
            }
        }
        return max_len;
    }
};

TEST_CASE("EXAMPLE") {
    std::string s{")()())"};
    REQUIRE(Solution().longestValidParentheses(s) == 4);
}
