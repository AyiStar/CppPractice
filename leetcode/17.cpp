// https://leetcode.com/problems/letter-combinations-of-a-phone-number
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>
#include <string>


class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) {
            return {};
        }
        char map[][5] {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        std::vector<std::string> ret;
        int n = static_cast<int>(digits.size());
        char str[5];  // digits.size() <= 4
        str[n] = '\0';
        backtracing(0, n, str, digits, ret, map);
        return ret;
    }

private:
    void backtracing(int i, int n, char *str, const std::string& digits,
                    std::vector<std::string>& ret,
                    char map[][5]) {
        if (i == n) {
            ret.emplace_back(str);
            return;
        }
        int digit = digits.at(i) - '2';
        for (int j = 0; map[digit][j] != '\0'; j++) {
            str[i] = map[digit][j];
            backtracing(i+1, n, str, digits, ret, map);
        }
        return;
    }
};


TEST_CASE("EXAMPLE") {
    std::string input("23");
    std::vector<std::string> answer{
        "ad","ae","af","bd","be","bf","cd","ce","cf"
    };
    REQUIRE_THAT(Solution().letterCombinations(input), Catch::Matchers::UnorderedEquals(answer));
}