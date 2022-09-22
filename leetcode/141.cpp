// https://leetcode.com/problems/linked-list-cycle/

#include <catch2/catch_test_macros.hpp>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    ListNode *slow = head;
    ListNode *fast = slow->next;
    while (fast != nullptr) {
      if (slow == fast) {
        return true;
      }
      slow = slow->next;
      fast = fast->next;
      if (fast != nullptr) {
        fast = fast->next;
      }
    }
    return false;
  }
};

TEST_CASE("SIMPLE_TEST") {
  ListNode *l = new ListNode(0);
  ListNode *p = l;
  for (int i = 0; i < 5; i++) {
    p->next = new ListNode(0);
    p = p->next;
  }
  REQUIRE(Solution().hasCycle(l) == false);
  p->next = l->next;
  REQUIRE(Solution().hasCycle(l) == true);
}
