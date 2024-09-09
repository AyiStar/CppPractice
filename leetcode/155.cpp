// https://leetcode.com/problems/min-stack

#include <catch2/catch_test_macros.hpp>
#include <vector>


class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        stack_.push_back(val);
        if (min_stack_.empty()) {
            min_stack_.push_back(val);
        } else {
            min_stack_.push_back(std::min(val, min_stack_.back()));
        }
    }
    
    void pop() {
        stack_.pop_back();
        min_stack_.pop_back();
    }
    
    int top() {
        return stack_.back();
    }
    
    int getMin() {
        return min_stack_.back();
    }

private:
    std::vector<int> stack_;
    std::vector<int> min_stack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */