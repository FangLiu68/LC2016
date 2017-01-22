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
 
 this method works when lists have non-repeated/ repeated values.
 */
struct comp{
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val; // min heap;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    if(lists.empty()) return NULL;
    
    // push each list's first node into priority queue
    priority_queue<ListNode*, vector<ListNode*>, comp> min_heap;
    for(int i = 0; i < lists.size(); ++i){
        if(lists[i]){
            min_heap.push(lists[i]);
        }
    }

    ListNode dummyNode(INT_MIN);
    ListNode* cur = &dummyNode;

    while(!min_heap.empty()){
        cur->next = min_heap.top();
        min_heap.pop();
        cur = cur->next;
        if(cur->next){
            min_heap.push(cur->next);
        }
    }
    
    return dummyNode.next;
}

/*
int main(){
    ListNode* node11 = new ListNode(1);
    ListNode* node12 = new ListNode(3);
    ListNode* node13 = new ListNode(5);
    ListNode* node14 = new ListNode(10);
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    ListNode* node21 = new ListNode(2);
    ListNode* node22 = new ListNode(3);
    ListNode* node23 = new ListNode(4);
    ListNode* node24 = new ListNode(8);
    node21->next = node22;
    node22->next = node23;
    node23->next = node24;
    ListNode* node31 = new ListNode(5);
    ListNode* node32 = new ListNode(6);
    ListNode* node33 = new ListNode(10);
    ListNode* node34 = new ListNode(15);
    node31->next = node32;
    node32->next = node33;
    node33->next = node34;
    vector<ListNode*> lists = {node11, node21, node31};
    ListNode* res = mergeKLists(lists);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}*/
