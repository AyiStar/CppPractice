// https://leetcode.com/problems/subsets
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>
#include <vector>



class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        std::vector<int> subset;
        backtracing(0, nums, subset, results);
        return results;
    }

private:
    void backtracing(int i,
                    const std::vector<int>& nums,
                    std::vector<int>& subset,
                    std::vector<std::vector<int>>& results) {
        if (i == static_cast<int>(nums.size())) {
            results.push_back(std::vector<int>(subset));
            return;
        }
        backtracing(i+1, nums, subset, results);
        subset.push_back(nums[i]);
        backtracing(i+1, nums, subset, results);
        subset.pop_back();
        return;
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> input{1, 2, 3};
    std::vector<std::vector<int>> results{
        {}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}
    };
    REQUIRE_THAT(Solution().subsets(input), Catch::Matchers::UnorderedEquals(results));
}