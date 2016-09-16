
//
//  Check and Find Cycle in Linked List.cpp
//  LC2016
//
//  Created by Fang Liu on 3/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// check if a given linked list has cycle. and find the start node of the cycle.

#include "LinkedList.h"


/*
 1 2
 */
bool hasCycle(ListNode* head){
    if(head == NULL || head->next == NULL) return false;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    
    return false;
}

ListNode* findCycle(ListNode* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL){
            return NULL;
        }else{
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
    }
    
    return NULL;
}