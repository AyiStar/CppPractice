// https://leetcode.com/problems/swap-nodes-in-pairs/

#include<catch2/catch_test_macros.hpp>


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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        
        ListNode *p = head, *q = head->next;
        while (p != nullptr && q != nullptr) {
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
            p = q->next;
            q = (p != nullptr) ? p->next : nullptr;
        }
        return head;
    }
};


TEST_CASE("SIMPLE_TEST") {
    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    ListNode *p = Solution().swapPairs(l);
    REQUIRE(p->val == 2);
    REQUIRE(p->next->val == 1);
}
