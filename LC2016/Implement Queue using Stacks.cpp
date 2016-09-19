//
//  Implement Queue using Stacks.cpp
//  LC2016
//
//  Created by Fang Liu on 9/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Implement the following operations of a queue using stacks.

 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
 Notes:
 You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */

/*
 stack 1    bottom1   <--top
 stack 2    bottom2   432<--top   pop(1)
 solution:
 head 1  2 3 4 ----  5 6  tail
 Stack1
 Stack2   0  9 8 7 6 5
 solution:
 (1) we regard stack 1 as the stack to insert/push new element in
 (2) we regard stack 2 as the stack to pop out element.
 When popping out an element, check stack 2,
 if not empty, then pop one element out
 if empty, then dump all data from stack 1 to stack 2
 (special case, if both stack 1 and 2 are empty, then return NULL);
 when push in, just push into stack 1;
 Time complexity: push O(1)
 pop() : amortized O(1)
 */

#include <stack>
#include <iostream>
using namespace std;

class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        swap();
        if(out.empty()) return;
        out.pop();
    }

    // Get the front element.
    int peek(void) {
        swap();
        if(out.empty()) return INT_MIN;
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.empty() && out.empty();
    }

    // when stack "out" is empty, push all elements from stack "in" to "out"
    void swap(){
        if(out.empty()){
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
    }
private:
    stack<int> in; // only push element into stack in
    stack<int> out; // only pop element from stack out
};
