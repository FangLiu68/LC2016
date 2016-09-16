//
//  LinkedList.h
//  LC2016
//
//  Created by Fang Liu on 3/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL){}
};

#endif /* LinkedList_h */
