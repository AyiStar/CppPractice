// https://leetcode.com/problems/find-median-from-data-stream

#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

class MedianFinder {
public:
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if (max_heap.empty() || num < max_heap[0]) {
            max_heap.push_back(num);
            std::push_heap(max_heap.begin(), max_heap.end());
        } else {
            min_heap.push_back(num);
            std::push_heap(min_heap.begin(), min_heap.end(), std::greater<>());
        }
        if (min_heap.size() > max_heap.size() + 1) {
            move_min_to_max();
        }
        if (max_heap.size() > min_heap.size() + 1){
            move_max_to_min();
        }
        n++;
    }
    
    double findMedian() {
        if (n % 2 == 0) {
            return (max_heap[0] + min_heap[0]) / 2.0;
        } else {
            return (max_heap.size() > min_heap.size()) ? max_heap[0]: min_heap[0];
        }
    }

private:
    std::vector<int> max_heap;
    std::vector<int> min_heap;
    int n;

    void move_max_to_min() {
        int moved = max_heap[0];
        std::pop_heap(max_heap.begin(), max_heap.end());
        max_heap.pop_back();
        min_heap.push_back(moved);
        std::push_heap(min_heap.begin(), min_heap.end(), std::greater<>());
    }

    void move_min_to_max() {
        int moved = min_heap[0];
        std::pop_heap(min_heap.begin(), min_heap.end(), std::greater<>());
        min_heap.pop_back();
        max_heap.push_back(moved);
        std::push_heap(max_heap.begin(), max_heap.end());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
TEST_CASE("EXAMPLE") {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    REQUIRE(std::abs(obj->findMedian() - 1.5) < 1e-7);
    obj->addNum(3);
    REQUIRE(std::abs(obj->findMedian() - 2) < 1e-7);
}