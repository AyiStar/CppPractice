// https://leetcode.com/problems/sort-list
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

private:
    ListNode* mergeSort(ListNode* begin) {
        int n = countLength(begin);
        if (n < 2) {
            return begin;
        }
        int mid = n / 2;  // mid >= 1
        ListNode *half{begin}, *prev{nullptr};
        for (int i = 0; i < mid; i++) {
            prev = half;
            half = half->next;
        }
        prev->next = nullptr;
        ListNode *l1 = mergeSort(begin);
        ListNode *l2 = mergeSort(half);
        
        // merge sorted lists
        ListNode *new_head{nullptr};
        if (l1->val <= l2->val) {
            new_head = l1;
            l1 = l1->next;
        } else {
            new_head = l2;
            l2 = l2->next;
        }
        ListNode *p = new_head;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        p->next = (l1 != nullptr) ? l1 : l2;

        return new_head;
    }

    int countLength(ListNode *l) {
        int n = 0;
        while (l != nullptr) {
            n++;
            l = l->next;
        }
        return n;
    }

    void printList(ListNode *l) {
        while (l != nullptr) {
            std::cout << l->val << ' ';
            l = l->next;
        }
        std::cout << std::endl;
    }
};


TEST_CASE("SIMPLE") {
    std::vector<int> vals{-1, 5, 3, 4, 0};
    std::vector<int> sorted_vals{-1, 0, 3, 4, 5};
    ListNode *head = new ListNode(), *p{head};    
    for (auto val: vals) {
        p->next = new ListNode(val);
        p = p->next;
    }
    ListNode *sorted = Solution().sortList(head->next);
    p = sorted;
    std::cout << std::endl;
    for (auto val: sorted_vals) {
        REQUIRE(p->val == val);
        p = p->next;
    }
}