// https://leetcode.com/problems/median-of-two-sorted-arrays

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>


class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int mid1 = findKthElement((n1 + n2 + 1) / 2, 0, n1-1, 0, n2-1, nums1, nums2);
        int mid2 = findKthElement((n1 + n2 + 2) / 2, 0, n1-1, 0, n2-1, nums1, nums2);
        return (mid1 + mid2) / 2.0;
    }

private:
    int findKthElement(int k, int l1, int r1, int l2, int r2, const std::vector<int>& nums1, const std::vector<int>& nums2) {
        int n1 = r1 - l1 + 1;
        int n2 = r2 - l2 + 1;
        
        if (n1 > n2) {
            return findKthElement(k, l2, r2, l1, r1, nums2, nums1);
        }
        if (n1 == 0) {
            return nums2[l2 + k - 1];
        }
        if (k == 1) {
            return std::min(nums1[l1], nums2[l2]);
        }

        int m1 = l1 + std::min(k / 2, n1) - 1;
        int m2 = l2 + std::min(k / 2, n2) - 1;
        if (nums1[m1] > nums2[m2]) {
            int filtered = std::min(k / 2, n2);
            return findKthElement(k - filtered, l1, r1, m2 + 1, r2, nums1, nums2);
        } else {
            int filtered = std::min(k / 2, n1);
            return findKthElement(k - filtered, m1 + 1, r1, l2, r2, nums1, nums2);
        }
    }
};


TEST_CASE("EXAMPLE") {
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    REQUIRE(Solution().findMedianSortedArrays(nums1, nums2) == (2 + 3) / 2.0);
}