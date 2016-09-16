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