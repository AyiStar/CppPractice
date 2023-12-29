// https://leetcode.com/problems/lru-cache
#include <catch2/catch_test_macros.hpp>
#include <map>


class LRUCache {
public:
    LRUCache(int capacity): capacity_(capacity), list_(new ListNode()) {
        ListNode *p{list_};
        for (int i = 0; i < capacity; i++) {
            p->next = new ListNode();
            p->next->prev = p;
            p = p->next;
        }
        p->next = list_;
        list_->prev = p;
    }
    
    int get(int key) {
        auto kv = map_.find(key);
        if (kv == map_.end()) {
            return -1;
        }
        auto *p = kv->second;
        int val = p->val;
        move_to_head(p);
        return val;
    }
    
    void put(int key, int value) {
        auto kv = map_.find(key);
        if (kv != map_.end()) {
            kv->second->val = value;
            move_to_head(kv->second);
            return;
        }
        
            auto *lu = list_->prev;
            if (map_.size() == capacity_) {
                map_.erase(lu->key);
            }
            lu->key = key;
            lu->val = value;
            map_[key] = lu;
            move_to_head(lu);
        
    }

    ~LRUCache() {
        delete list_;
    }

private:

    struct ListNode {
        int key;
        int val;
        ListNode *prev;
        ListNode *next;
        ListNode(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
        ListNode(): ListNode(0, 0) {}
    };

    std::size_t capacity_;
    std::map<int, ListNode*> map_;
    ListNode *list_;

    void move_to_head(ListNode *p) {
        // remove
        p->prev->next = p->next;
        p->next->prev = p->prev;
        // insert
        p->next = list_->next;
        p->prev = list_;
        list_->next = p;
        p->next->prev = p;
    }
};


TEST_CASE("EXAMPLE") {

    LRUCache lRUCache = LRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    REQUIRE(lRUCache.get(1) == 1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    REQUIRE(lRUCache.get(2) == -1);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    REQUIRE(lRUCache.get(1) == -1);    // return -1 (not found)
    REQUIRE(lRUCache.get(3) == 3);    // return 3
    REQUIRE(lRUCache.get(4) == 4);    // return 4

}