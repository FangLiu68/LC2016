//
//  Reverse Linked List.cpp
//  LC2016
//
//  Created by Fang Liu on 3/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// reverse a single linked list

#include "LinkedList.h"

ListNode* reverseLinkedListIter(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* cur = head;
    ListNode* pre = NULL;
    
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        //cur = next;
        pre = cur; // you must move pre first !!!
        cur = next;
    }
    
    return pre;
}


//        1 -> 2 -> 3 -> 4 -> NULL
// NULL<- 1 <- 2 <- 3 <- 4

/*
 1st call R-func:    NULL  ←     Node1 ←    Node2 ←    Node3                newHead=N3
                                 head       next
 ======================================================================================
 2nd call R-func:                Node1 →    Node2 ←    Node3                newHead=N3
                                            head       next
 ======================================================================================
 3rd call R-func:                Node1 →    Node2 →     Node3→     NULL     newHead=N3
 head       next
 */

ListNode* reverseLinkedListRecur(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* cur = head;
    ListNode* next_node = head->next;
    
    ListNode* newHead = reverseLinkedListRecur(next_node);
    
    next_node->next = cur;
    cur->next = NULL;
    return newHead;
}

/*
int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    head->next = node2;
    node2->next = node3;
    
    ListNode* res = reverseLinkedListRecur(head);
    while(res){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}*/
