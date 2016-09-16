//
//  Queue by Two Stacks.cpp
//  LC2016
//
//  Created by Fang Liu on 3/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Implement a queue by using two stacks. 
 The queue should provide size(), isEmpty(), push(), front(), pop() operations. 
 when the queue is empty, front() should return -1;
 */

#include <stack>
#include <iostream>
using namespace std;

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
