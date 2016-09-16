//
//  Merge K Sorted Lists.cpp
//  LC2016
//
//  Created by Fang Liu on 4/7/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Merge K sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 Assumptions
 None of the lists is null.
*/

#include "LinkedList.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
 we could use a min heap of size k.
 The heap is first initialized with the smallest element from  each list.
 Then as we extract the nodes out from the heap, we must remember to insert its next node into the heap.
 As each insert operation into the heap costs log(k) and there are a total of n*k elements, teh total runtime complexity is O(nk logk)
 Ignoring the extra space that is used to store the output list, we only use extra space of O(K) due to the heap.
 */
struct comp{
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val >= node2->val; // min heap;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    if(lists.empty()) return NULL;
    ListNode dummyNode(INT_MIN);
    ListNode* cur = &dummyNode;
    
    // push each list's first node into priority queue
    priority_queue<ListNode*, vector<ListNode*>, comp> min_heap;
    for(int i = 0; i < lists.size(); ++i){
        if(lists[i]){
            min_heap.push(lists[i]);
        }
    }
    
    while(!min_heap.empty()){
        ListNode* top = min_heap.top();
        cur->next = top;
        cur = cur->next;
        min_heap.pop();
        if(top->next){
            min_heap.push(top->next);
        }
    }
    
    return dummyNode.next;
}