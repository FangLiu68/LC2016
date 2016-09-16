//
//  Reorder Linked List.cpp
//  LC2016
//
//  Created by Fang Liu on 3/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Reorder the given singly-linked list N1 -> N2 -> N3 -> N4 -> … -> Nn -> null to be N1- > Nn -> N2 -> Nn-1 -> N3 -> Nn-2 -> … -> null
 Examples
 L = null, is reordered to null
 L = 1 -> null, is reordered to 1 -> null
 L = 1 -> 2 -> 3 -> 4 -> null, is reordered to 1 -> 4 -> 2 -> 3 -> null
 L = 1 -> 2 -> 3 -> null, is reordred to 1 -> 3 -> 2 -> null
 */

#include "LinkedList.h"

/*
 So the algorithm implemented below can be summarized as:
 Step 1  Find the middle pointer of the linked list (you can use the slow/fast pointers)
 Step 2  Reverse the second part of the linked list (from middle->next to the end)
 Step 3  Do the reordering. (inset every element in the second part in between the elements in the first part)
 */

ListNode* findMidNode(ListNode* head);
ListNode* reverseList(ListNode* head);
ListNode* mergeTwoLists(ListNode* one, ListNode* two);

ListNode* findMidNode(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* mergeTwoLists(ListNode* one, ListNode* two){
    if(one == NULL) return two;
    if(two == NULL) return one;
    
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
    
    cur->next = one? one:two;
    return dummy.next;
}

ListNode* reverseList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* pre = NULL;
    ListNode* cur = head;
    
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

ListNode* reorderList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* midNode = findMidNode(head);
    
    ListNode* one = head;
    ListNode* two = midNode->next;
    midNode->next = NULL;
    
    two = reverseList(two);
    
    return mergeTwoLists(one, two);
}

/*
int main(){
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    //ListNode* node3 = new ListNode(3);
    //ListNode* node4 = new ListNode(4);
    head->next = node2;
   // node2->next = node3;
    //node3->next = node4;
    ListNode* res = reorderList(head);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}
*/