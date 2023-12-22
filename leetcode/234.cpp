// https://leetcode.com/problems/palindrome-linked-list
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
    bool isPalindrome(ListNode* head) {
        int n{0};
        
        // store len(list) in n
        for (auto *p = head; p != nullptr; p = p->next) {
            n++;
        }

        ListNode *mid{head}, *tail{nullptr};
        int mid_point{n / 2};
        for (int i = 0; i < mid_point; i++) {
            mid = mid->next;
        }
        { // reverse mid
            ListNode *prev{nullptr}, *curr{mid};
            while (curr != nullptr) {
                ListNode *next{curr->next};
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            tail = prev;
        }

        // compare 
        bool is_palindrome{true};
        {
            ListNode *p{head}, *q{tail};
            for (int i = 0; i < mid_point; i++) {
                if (p->val != q->val) {
                    is_palindrome = false;
                    break;
                }
                p = p->next;
                q = q->next;
            }
        }

        // recover list
        {
            ListNode *prev{nullptr}, *curr{tail};
            while (curr != nullptr) {
                ListNode *next{curr->next};
                curr->next = prev;
                prev = curr;
                curr = next;
            }
        }

        return is_palindrome;
    }
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}