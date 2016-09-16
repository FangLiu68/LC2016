//
//  Merge Two Sorted Lists.cpp
//  LC2016
//
//  Created by Fang Liu on 3/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Merge two sorted lists into one large sorted list.
 Examples
 L1 = 1 -> 4 -> 6 -> null, L2 = 2 -> 5 -> null, merge L1 and L2 to 1 -> 2 -> 4 -> 5 -> 6 -> null
 L1 = null, L2 = 1 -> 2 -> null, merge L1 and L2 to 1 -> 2 -> null
 L1 = null, L2 = null, merge L1 and L2 to null
 
 Idea:
 Since we don’t know which list’s head value is smaller, we need to set a dummy node as new list head’s previous node, as we iterate through l1 and l2, we will connect the node with smaller value after the dummy node, and the iterate ends whenever we meet NULL.
 The left sublist’s smallest value is guaranteed larger than the last node in our new sorted list.
 We could directly connect the left sublist.
 
 Complexity:
 Each node visit once
 Time O(N), space O(1)
 */

#include "LinkedList.h"


ListNode* merge_two_sorted_lists(ListNode* one, ListNode* two){
    if(one == NULL) return two;
    if(two == NULL) return one;
    
    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    
    while(one && two){
        if(one->val <= two->val){
            cur->next = one;
            one = one->next;
        }else{
            cur->next = two;
            two = two->next;
        }
        cur = cur->next;
    }
    
    cur->next = one? one:two;
    
    return dummy.next;
}
