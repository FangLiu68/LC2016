//
//  Insert in Sorted List.cpp
//  LC2016
//
//  Created by Fang Liu on 3/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// insert a node in sorted linked list

#include "LinkedList.h"

ListNode* insert_to_sorted_List(ListNode* head, int value){
    if(head == NULL){
        return new ListNode(value);
    }
    
    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    cur->next = head;
    
    // find insert position
    while(cur->next && value > cur->next->val){
        cur = cur->next;
    }
    
    // insert
    ListNode* insertNode = new ListNode(value);
    insertNode->next = cur->next;
    cur->next = insertNode;
    
    return dummy.next;
}