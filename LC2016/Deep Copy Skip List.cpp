//
//  Deep Copy Skip List.cpp
//  LC2016
//
//  Created by Fang Liu on 4/7/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 A skip list is a special type of linked list, where each of the nodes has a forward pointer to another node in the front and forward pointers are guaranteed to be in non-descending order.
 Make a deep copy of the original skip list.
 */

#include <unordered_map>
#include <iostream>
using namespace std;

struct skipListNode{
    int val;
    skipListNode* next;
    skipListNode* forward;
    skipListNode(int v) : val(v), next(NULL), forward(NULL){}
};

skipListNode* deepCopy(skipListNode* head){
    if(head == NULL){
        return NULL;
    }
    
    unordered_map<skipListNode*, skipListNode*> mp;
    
    // create the copied head
    skipListNode* newHead = new skipListNode(head->val);
    
    // put the head<->copied head pair into map
    mp[head] = newHead;
    
    skipListNode* cur = newHead;
    
    while(head){
        if(head->next){
            if(mp.find(head->next) == mp.end()){
                mp[head->next] = new skipListNode(head->next->val);
            }
            cur->next = mp[head->next];
        }
        
        if(head->forward){
            if(mp.find(head->forward) == mp.end()){
                mp[head->forward] = new skipListNode(head->forward->val);
            }
            cur->forward = mp[head->forward];
        }
        
        head = head->next;
        cur = cur->next;
    }
    
    return newHead;
}