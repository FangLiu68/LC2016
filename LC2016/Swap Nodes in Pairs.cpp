//
//  Swap Nodes in Pairs.cpp
//  LC2016
//
//  Created by Fang Liu on 9/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include "LinkedList.h"

/*
Swap nodes in pairs
Given a linked list, swap every two adjacent nodes and return its head.
For example:
Given 1->2->3->4, you should return the list as 2->1->4->3
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/*
Solution 1: recursion
Idea:
Same as the recursion solution idea of <reverse single linked list>
After recursion is how the pointers change within one pair and between pairs

Complexity:
Each node we visit twice
Time O(N), space O(1)
*/

ListNode* swapPairs_recur(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    
    // Given 1->2->3->4, return 2->1->4->3
    ListNode* node1 = head;
    ListNode* node2 = node1->next;
    
    ListNode* newHead = swapPairs_recur(node2->next);
    
    node2->next = node1;
    node1->next = newHead;
    
    // return each sub list’s reversed head to upper level
    return node2;
}

/*
 Solution 2: iteration
     1->  2-> 3->  4, return 2->1-> 4->3
 pre cur
 
 We call every two nodes together is a pair.
 For each pair, there are two pointers we need to change:
 The one between the pair, and the one connected with two pairs.
 When we change pointer direction of 2->1, we need to keep tracking node 3 so the following list won’t get lost.
 Therefore for each pair, there are three nodes we need to keep tracking: current pair, and the following node (example: node1, node2, node3)
 Since we will change the head node of this list, we should create a dummy node(head node’s previous node) to start iterate.
 
 Complexity:
 We visit each node once
 Time O(N), space O(1)
 */
ListNode* swapPairs_iter(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* cur = head;
    
    while(cur && cur->next){
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = cur;
        pre = cur;
        cur = cur->next;
    }
    
    return dummy->next;
}
