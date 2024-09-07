// https://leetcode.com/problems/partition-labels/description

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::map<char, int> last_index;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            last_index[s[i]] = i;
        }

        std::vector<int> partitions;
        int count = 0;
        int bound = 0;
        for (int i = 0; i < n; i++) {
            if (i > bound) {
                partitions.push_back(count);
                count = 0;
            }
            count++;
            bound = std::max(bound, last_index[s[i]]);
        }
        partitions.push_back(count);
        return partitions;
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().partitionLabels("ababcbacadefegdehijhklij") == std::vector{9, 7, 8});
}