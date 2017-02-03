//
//  Remove nodes contain vowels.cpp
//  LC2016
//
//  Created by Fang Liu on 2/1/17.
//  Copyright © 2017 Fang Liu. All rights reserved.
//

/*
 remove all linked list nodes contain vowels
 vowels: a, e, i, o, u
 'a'->'i'->'e'->null
 */


#include <iostream>
using namespace std;

struct Node{
    char val;
    Node* next;
    Node(char p): val(p), next(NULL){}
};

Node* remove_vowel(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node dummyNode('x');
    Node* cur = &dummyNode;
    while(cur->next){
        char c = cur->next->val;
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            Node* pNext = cur->next;
            cur->next = cur->next->next;
            delete pNext;
            pNext = NULL;
        }else{
            cur = cur->next;
        }
    }
    return dummyNode.next;
}



