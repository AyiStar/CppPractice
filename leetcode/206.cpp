// https://leetcode.com/problems/reverse-linked-list
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

    ListNode* reverseList(ListNode* head) {
        ListNode *a{nullptr}, *b{head}, *tmp{nullptr};
        while (b != nullptr) {
            tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        return a;
    }


    ListNode* reverseListOrigin(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *a{head}, *b{head->next}, *tmp{nullptr};
        while (b != nullptr) {
            tmp = b->next;
            b->next = a;
            a = b;
            b = tmp;
        }
        head->next = nullptr;
        return a;
    }
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}