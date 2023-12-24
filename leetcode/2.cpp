// https://leetcode.com/problems/add-two-numbers/
#include <catch2/catch_test_macros.hpp>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry{0};
        ListNode *head = new ListNode(), *sum{head};
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            sum->next = new ListNode();
            sum = sum->next;
            int digit{carry};
            if (l1 != nullptr) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                digit += l2->val;
                l2 = l2->next;
            }
            sum->val = digit % 10;
            carry = digit / 10;
        }
        sum = head->next;
        delete(head);
        return sum;
    }
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}
