// https://leetcode.com/problems/decode-string

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::vector<char> stk;
        int num;
        std::string str;
        for (char c: s) {
            if (c == ']') {
                // pop string
                str = std::string{};
                while (stk.back() != '[') {
                    str.insert(str.begin(), stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                // pop number
                num = 0;
                int base = 1;
                while (!stk.empty() && std::isdigit(stk.back())) {
                    num += base * (stk.back() - '0');
                    base *= 10;
                    stk.pop_back();
                }
                // push string
                for (int i = 0; i < num; i++) {
                    for (char c: str) {
                        stk.push_back(c);
                    }
                }
            } else {
                stk.push_back(c);
            }
        }
        return {stk.begin(), stk.end()};
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().decodeString("3[a]2[bc]") == "aaabcbc");
    REQUIRE(Solution().decodeString("3[a2[c]]") == "accaccacc");
}