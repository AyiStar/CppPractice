// https://leetcode.com/problems/n-th-tribonacci-number
#include <catch2/catch_test_macros.hpp>

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
};


TEST_CASE("EXAMPLE") {
    REQUIRE(Solution().tribonacci(4) == 4);
    REQUIRE(Solution().tribonacci(25) == 1389537);
}
