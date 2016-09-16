//
//  Palindrome Linked List.cpp
//  LC2016
//
//  Created by Fang Liu on 9/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Palindrome Linked List
 Given a singly linked list, determine if it is a palindrome.
 Follow up:
 Could you do it in O(N) time and O(1) space?
 */

#include "LinkedList.h"
#include <stack>

/*
 Solution 1: use stack
 Idea:
 Use stack to store first half list into stack. Pop each node one by one, and compare it with the rest of the list.
 
 Complexity:
 We visit each node once, and use stack to contain half the nodes.
 Time O(N), space O(N/2)=O(N)
 */

// a b a; a a
bool isPalindrome_stack(ListNode* head) {
    if(head == NULL) return true;
    stack<ListNode*> stk;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next){
        stk.push(slow);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) slow = slow->next;
    
    while(!stk.empty()){
        ListNode* cur = stk.top();
        stk.pop();
        if(cur->val != slow->val){
            return false;
        }
        slow = slow->next;
    }
    
    return true;
}


/*
 Solution 2: reverse the right half sub-list
 Idea:
 1. Find the middle node of the list
 2. Reverse the right half list
 3. Compare left half list and the right half reversed list
 
 Complexity:
 Each node is visited twice. And we don’t use extra space to contain nodes.
 Time O(N), space O(1)
 */

ListNode* reverse_rightHalf(ListNode* head);
ListNode* find_middleNode(ListNode* head);
bool isPalindrome_reverseRightHalf(ListNode* head){
    if(head == NULL || head->next == NULL){
        return true;
    }
    
    ListNode* cur = head;
    ListNode* rightHead = find_middleNode(cur);
    ListNode* reverse_rightHead = reverse_rightHalf(rightHead);
    ListNode* cur_right = reverse_rightHead;
    while(cur_right){
        if(cur->val != cur_right->val){
            return false;
        }
        cur = cur->next;
        cur_right = cur_right->next;
    }
    
    return true;
}

// find the middle node of the list, return the right half list's head node
ListNode* find_middleNode(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // a b a; a a
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast){
        slow = slow->next;
    }
    
    return slow;
}

// reverse a single linked list
ListNode* reverse_rightHalf(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* pre = NULL;
    ListNode* cur = head;
    
    while(cur){
        ListNode* next_node = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_node;
    }
    
    return pre;
}
