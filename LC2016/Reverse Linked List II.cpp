//
//  Reverse Linked List II.cpp
//  LC2016
//
//  Created by Fang Liu on 9/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given  1-> 2->3->4 ->5->NULL, m = 2 and n = 4,
 return 1-> 4->3->2 ->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 ≤ m ≤ n ≤ length of list.
 */

#include "LinkedList.h"

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNode dummy(-1);
    ListNode* start = &dummy;
    start->next = head;
    ListNode* slow = start;

    for(int i=0; i<m-1; ++i){
        slow = slow->next; // slow point to the end of left list
    }

    ListNode* old_head = slow->next;
    ListNode* fast = old_head;
    for(int i=0; i<n-m; ++i){
        fast = fast->next;
    }
    ListNode* old_tail = fast;
    fast = fast->next; // fast point to head of right list

    ListNode* cur = old_head;
    ListNode* pre = fast;

    while(cur != fast){
        ListNode* next_node = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_node;
    }

    slow->next = old_tail;
    return dummy.next;
}
