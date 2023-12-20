// https://leetcode.com/problems/intersection-of-two-linked-lists
#include <catch2/catch_test_macros.hpp>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pa{headA}, *pb{headB};
        
        int m{0}, n{0};
        while (pa != nullptr) {
            m++;
            pa = pa->next;
        }
        while (pb != nullptr) {
            n++;
            pb = pb->next;
        }

        pa = headA;
        pb = headB;
        while (m > n) {
            pa = pa->next;
            m--;
        }
        while (m < n) {
            pb = pb->next;
            n--;
        }

        // Now m == n
        // A and B are symmetry
        while (pa != nullptr && pb != nullptr) {
            if (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }

        return nullptr;
    }
};


TEST_CASE("NO-TEST") {
    REQUIRE(true);
}