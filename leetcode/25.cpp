// https://leetcode.com/problems/reverse-nodes-in-k-group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *left{dummy}, *right{dummy};
        while (true) {
            // forward k steps
            right = left;
            for (int i = 0; i < k && right != nullptr; i++) {
                right = right->next;
            }
            if (right == nullptr) {
                break;
            }
            
            // reverse (left, right]
            ListNode *begin{left->next}, *end{right->next};
            ListNode *prev{left}, *curr{begin};
            while (curr != end) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            begin->next = end;
            left->next = right;
            
            left = begin;
       }
       ListNode *new_head = dummy->next;
       delete dummy;
       return new_head;
    }
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}