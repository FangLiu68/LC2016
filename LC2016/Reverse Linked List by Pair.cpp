//
//  Reverse Linked List by Pair.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Reverse pairs of elements in a singly-linked list.
 
 Examples
 L = null, after reverse is null
 L = 1 -> null, after reverse is 1 -> null
 L = 1 -> 2 -> null, after reverse is 2 -> 1 -> null
 L = 1 -> 2 -> 3 -> null, after reverse is 2 -> 1 -> 3 -> null
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* cur = head;
    ListNode* node_curNext = cur->next;
    ListNode* nnext = node_curNext->next;
    
    cur->next = swapPairs(nnext);
    node_curNext->next = cur;
    
    return node_curNext;
}