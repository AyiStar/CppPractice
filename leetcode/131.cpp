// https://leetcode.com/problems/palindrome-partitioning
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>


class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        results_.clear();
        std::vector<int> split_points;
        sv_ = s;
        n_ = static_cast<int>(s.size());
        if (n_ > 0) {
            backtrace(split_points, 0);
        }
        return results_;
    }

private:
    void backtrace(std::vector<int>& split_points, int i) {
        split_points.push_back(i);
        if (i == n_) {
            results_.push_back(gen_split(split_points));
            split_points.pop_back();
            return;
        }
        
        for (int j = i + 1; j <= n_; j++) {
            if (is_palindrome(sv_.substr(i, j - i))) {
                backtrace(split_points, j);
            }
        }
        split_points.pop_back();
    }

    bool is_palindrome(const std::string_view s) {
        int i = 0, j = static_cast<int>(s.size()) - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }

    std::vector<std::string> gen_split(const std::vector<int>& split_points) {
        std::vector<std::string> v;
        for (int i = 0; i < static_cast<int>(split_points.size()) - 1; i++) {
            auto substr = sv_.substr(split_points[i], split_points[i+1] - split_points[i]);
            v.push_back({substr.begin(), substr.end()});
        }
        return v;
    }

private:
    std::vector<std::vector<std::string>> results_;
    std::string_view sv_;
    int n_;
};


TEST_CASE("EXAMPLE") {
    auto ret1 = Solution().partition("");
    REQUIRE(ret1.empty());

    auto ret2 = Solution().partition("a");
    REQUIRE_THAT(ret2, Catch::Matchers::UnorderedEquals(decltype(ret2){{"a"}}));

    auto ret3 = Solution().partition("aab");
    REQUIRE_THAT(ret3, Catch::Matchers::UnorderedEquals(decltype(ret3){{"a", "a", "b"}, {"aa", "b"}}));
}