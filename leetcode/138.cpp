// https://leetcode.com/problems/copy-list-with-random-pointer
#include <catch2/catch_test_macros.hpp>


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        for (auto *p = head; p != nullptr;) {
            auto *next = p->next;
            p->next = new Node(p->val);
            p->next->next = next;
            p = next;
        }
        for (auto *p = head; p != nullptr; p = p->next->next) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
        }
        auto *copy_head{head->next};
        for (auto *p = head; p != nullptr; p = p->next) {
            auto *this_copy = p->next, *next_origin = this_copy->next;
            this_copy->next = (next_origin != nullptr) ? next_origin->next : nullptr;
            p->next = next_origin;
        }
        return copy_head;
    }
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}