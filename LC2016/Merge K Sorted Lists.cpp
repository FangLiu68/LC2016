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
 Method 1:
 we could use a min heap of size k.
 The heap is first initialized with the smallest element from  each list.
 Then as we extract the nodes out from the heap, we must remember to insert its next node into the heap.
 
 time:
 build size k heap use O(K)
 every node get push/pop of heap once, each time cost O(logK)
 so totally runtime: O(K)+O(NK* (logK+logK)) = O(NKlogK)
 
 space:
 O(K) for building heap.
 */
struct comp{
    bool operator()(ListNode* node1, ListNode* node2){
        return node1->val > node2->val; // min heap;
    }
};

ListNode* mergeKLists_heap(vector<ListNode*>& lists){
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
 Method 2:
 for those k sorted lists: lists[0], lists[1], lists[2]... lists[k-3], lists[k-2], lists[k-1]
 we first merge lists[0] and lists[k-1], and set result as lists[0]
 then merge lists[1] and lists[k-2], set result as lists[1]
 ...
 after done each round, then go over again to merge the two pairs, until we only have one list left.
 
 Time:
 while loop一共执行了logK次（因为每次lists的数量减半）
 每次while loop要把每个list都走一遍，所以是 O(NK)
 所以一共时间为 O(NKlogK). 和上一种做法时间一样。
 */
ListNode* helper_mergeTwoLists(ListNode* l1, ListNode* l2);
ListNode* mergeKLists_byPair(vector<ListNode*>& lists) {
    if (lists.empty()) return NULL;
    int len = lists.size();
    while (len > 1) {
        for (int i = 0; i < len / 2; ++i) {
            lists[i] = helper_mergeTwoLists(lists[i], lists[len - 1 - i]);
        }
        len = (len + 1) / 2;
    }

    return lists[0];
}

ListNode* helper_mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    ListNode dummyNode(INT_MIN);
    ListNode* cur = &dummyNode;
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1? l1:l2;
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
