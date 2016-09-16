//
//  Remove Nth Node From End of List.cpp
//  LC2016
//
//  Created by Fang Liu on 9/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Remove Nth Node From End of List
 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
 Given linked list: 1->2->3->4->5, and n = 2
 After removing the second node from the end, the linked list becomes 1->2->3->5
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 
 Idea:
 Not quite sure what “n will always be valid” exactly means, so I’ll consider all situations.
 1. If n<=0, do nothing
 2. If n==list.length, we need to delete the head node, so we need set a dummy node as the head node’s previous node.
 3. If n>list.length, we return NULL
 4. Normal cases: 0<n<list.length
 We use slow/fast pointer to find the nth node from the end. (fast moves n steps first)
 
 Complexity:
 We visit each node once.
 Time O(N), space O(1)
 */

#include "LinkedList.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL || n <= 0){
        return head;
    }
    
    ListNode dummy(0);
    ListNode* start = &dummy;
    start->next = head;
    
    ListNode* slow = start;
    ListNode* fast = start;
    
    for(int i=0; i<n; ++i){
        if(fast == NULL) return NULL; // if n > list.length
        fast = fast->next;
    }
    
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    
    ListNode* remove = slow->next;
    slow->next = remove->next;
    delete remove;
    remove = NULL;
    return dummy.next;
}
