// https://leetcode.com/problems/permutations/
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        std::vector<int> curr;
        backtrace(nums, curr, ret);
        return ret;
    }

private:
    void backtrace(std::vector<int>& nums, std::vector<int>& curr, std::vector<std::vector<int>>& ret) {
        if (nums.empty()) {
            ret.push_back(curr);
            return;
        }
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; i++) {
            auto tmp{nums};
            tmp.erase(tmp.begin() + i);
            curr.push_back(nums[i]);
            backtrace(tmp, curr, ret);
            curr.pop_back();
        }
        return;
    }

};


TEST_CASE("EXAMPLE") {
    std::vector<int> input{1, 2, 3};
    auto ret = Solution().permute(input);
    std::vector<std::vector<int>> answer {
        {1, 2, 3}, {1, 3, 2},
        {2, 1, 3}, {2, 3, 1},
        {3, 1, 2}, {3, 2, 1}
    };
    REQUIRE(ret == answer);
}