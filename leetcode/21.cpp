// https://leetcode.com/problems/merge-two-sorted-lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(), *p{head};
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = (list1 == nullptr) ? list2 : list1;
        p = head->next;
        delete(head);
        return p;
    }
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}
