// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <catch2/catch_test_macros.hpp>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail = head;
        int i = 0;
        while (tail != nullptr && i < n) {
            tail = tail->next;
            i++;
        }

        ListNode *p = nullptr, *q = head;
        while (tail != nullptr) {
            p = q;
            q = q->next;
            tail = tail->next;
        }

        // remove
        if (p != nullptr) {
            p->next = q->next;
        }
        else {
            head = q->next;
        }
        delete(q);

        return head;
    }
};


TEST_CASE("NO_TEST") {
    ;
}