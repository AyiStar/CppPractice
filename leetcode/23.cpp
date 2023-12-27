// https://leetcode.com/problems/merge-k-sorted-lists
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <queue>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // assume lists can be altered
        std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeCompare> pq;
        for (const auto& p: lists) {
            if (p != nullptr) {
                pq.push(p);
            }
        }
        ListNode *merged_head = new ListNode(), *p{merged_head};
        while (!pq.empty()) {
            auto *next = pq.top();
            pq.pop();
            p->next = next;
            p = next;
            if (p->next != nullptr) {
                pq.push(p->next);
            }
        }
        p = merged_head->next;
        delete(merged_head);
        return p;
    }

private:
    struct ListNodeCompare {
        bool operator() (const ListNode* a, const ListNode* b) {
            return (a->val > b->val);
        }
    };
};


TEST_CASE("NO_TEST") {
    REQUIRE(true);
}
