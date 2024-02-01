// https://leetcode.com/problems/combination-sum
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        combination_.clear();
        n_ = static_cast<int>(candidates.size());
        sum_ = 0;
        target_ = target;
        std::vector<std::vector<int>> ret;
        backtracing(0, candidates, ret);
        return ret;
    }

private:

    void backtracing(int i, const std::vector<int>& candidates, std::vector<std::vector<int>>& ret) {
        if (i == n_ || sum_ >= target_) {
            if (sum_ == target_) {
                ret.emplace_back(combination_);
            }
            return;
        }
        int k = 0;
        backtracing(i+1, candidates, ret);
        while (sum_ < target_ && k < MAX_LEN_) {
            sum_ += candidates[i];
            combination_.push_back(candidates[i]);
            backtracing(i+1, candidates, ret);
            k++;
        }
        combination_.erase(combination_.end() - k, combination_.end());
        sum_ -= candidates[i] * k;
        return;
    }

    std::vector<int> combination_;
    int target_;
    int n_;
    int sum_;
    const int MAX_LEN_ = 150;
};


TEST_CASE("NAIVE") {
    std::vector<int> input{7};
    std::vector<std::vector<int>> ans{
        {7}
    };
    REQUIRE_THAT(Solution().combinationSum(input, 7),
                Catch::Matchers::UnorderedEquals(ans));
}

TEST_CASE("EXAMPLE") {
    std::vector<int> input{2, 3, 6, 7};
    std::vector<std::vector<int>> ans{
        {2, 2, 3}, {7}
    };
    REQUIRE_THAT(Solution().combinationSum(input, 7),
                Catch::Matchers::UnorderedEquals(ans));
}