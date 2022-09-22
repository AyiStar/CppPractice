// https://leetcode.com/problems/linked-list-cycle-ii/

#include <catch2/catch_test_macros.hpp>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head, *fast = head;
    bool has_cycle = false;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        has_cycle = true;
        break;
      }
    }
    if (!has_cycle) {
      // delete (head);
      return nullptr;
    }
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    // delete (head);
    return slow;
  }

private:
  void print_pointers(ListNode *slow, ListNode *fast) {
    std::cout << "Slow: " << ((slow) ? slow->val : -1);
    std::cout << "Fast: " << ((fast) ? fast->val : -1) << std::endl;
  }
};

TEST_CASE("SIMPLE_TEST") {
  ListNode *l = new ListNode(0);
  ListNode *p = l;
  for (int i = 1; i <= 5; i++) {
    p->next = new ListNode(i);
    p = p->next;
  }
  REQUIRE(Solution().detectCycle(l) == nullptr);
  p->next = l->next->next;
  REQUIRE(Solution().detectCycle(l)->val == 2);
}
