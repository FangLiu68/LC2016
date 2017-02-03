//
//  Remove Dup in Sorted Linked List.cpp
//  LC2016
//
//  Created by Fang Liu on 2/1/17.
//  Copyright © 2017 Fang Liu. All rights reserved.
//

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

#include "LinkedList.h"

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL) return NULL;
    ListNode* cur = head;
    while(cur->next){
        if(cur->next->val == cur->val){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            temp = NULL;
        }else{
            cur = cur->next;
        }
    }
    return head;
}
