//
//  Merge Two Lists Alternatively.cpp
//  LC2016
//
//  Created by Fang Liu on 3/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 l1 = 1 2 3 4 5;
 l2 = 6 7;
 l = 1 6 2 7 3 4 5
 l1 = 1 2;
 l2 = 3 4 5 6 7; then
 l = 1 3 2 4 5 6 7
 */

#include "LinkedList.h"

ListNode* merge_two_lists_alternatively(ListNode* one, ListNode* two){
    if(one == NULL){
        return two;
    }
    if(two == NULL){
        return one;
    }
    
    ListNode dummy(INT_MIN);
    ListNode* cur = &dummy;
    
    while(one && two){
        ListNode* one_next = one->next;
        ListNode* two_next = two->next;
        
        cur->next = one;
        cur->next->next = two;
        
        one = one_next;
        two = two_next;
        
        cur = cur->next->next;
    }
    
    cur->next = one?one:two;
    
    return dummy.next;
}

/*
int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node5->next = node6;
    ListNode* res = merge_two_lists_alternatively(node5, node1);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
*/