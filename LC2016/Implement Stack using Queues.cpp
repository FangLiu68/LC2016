//
//  Implement Stack using Queues.cpp
//  LC2016
//
//  Created by Fang Liu on 9/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Implement the following operations of a stack using queues.

 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 empty() -- Return whether the stack is empty.
 Notes:
 You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

#include <deque>
#include <iostream>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        deq.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!deq.empty()){
            deq.pop_back();
        }
    }

    // Get the top element.
    int top() {
        if(!deq.empty()){
            return deq.back();
        }else{
            return INT_MIN;
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return deq.empty();
    }
private:
    deque<int> deq;
};
