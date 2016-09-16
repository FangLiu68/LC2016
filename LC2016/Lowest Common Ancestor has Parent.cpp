//
//  Lowest Common Ancestor has Parent.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given two nodes in a binary tree (with parent pointer available), find their lowest common ancestor.
 Assumptions
 There is parent poiner for the nodes in the binary tree
 The given two nodes are not guaranteed to be in the binary tree
 */

#include "BinaryTree.h"
#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNodeP{
    int val;
    TreeNodeP* left;
    TreeNodeP* right;
    TreeNodeP* parent;
    TreeNodeP(int v) : val(v), left(NULL), right(NULL), parent(NULL){}
    TreeNodeP(int v, TreeNodeP* p) : val(v), left(NULL), right(NULL), parent(p) {}
};

TreeNodeP* LCA_hasParent(TreeNodeP* one, TreeNodeP* two) {
    // find len1, len2
    // get diff of len1, len2; move one of them until they are with same length
    if(one == NULL || two == NULL){
        return NULL;
    }
    
    int len1 = 0;
    int len2 = 0;
    TreeNodeP* cur_one = one;
    TreeNodeP* cur_two = two;
    
    while(cur_one){
        len1++;
        cur_one = cur_one->parent;
    }
    
    while(cur_two){
        len2++;
        cur_two = cur_two->parent;
    }
    
    int diff = abs(len1 - len2);
    
    if(len1 > len2){
        for(int i=0; i<diff; ++i){
            one = one->parent;
        }
    }else if(len2 > len1){
        for(int i=0; i<diff; ++i){
            two = two->parent;
        }
    }
    
    while(one!=NULL && two!=NULL && one != two){
        one = one->parent;
        two = two->parent;
    }
    
    return one;
}

//====================================================
// 下面和上面的做法一样，只是分开解了

int getLen(TreeNodeP* node){
    if(node == NULL){
        return 0;
    }
    
    int len = 0;
    
    while(node){
        len++;
        node = node->parent;
    }
    
    return len;
}

TreeNodeP* mergeNode(TreeNodeP* one, TreeNodeP* two, int len_diff){
    if(len_diff < 0){
        return mergeNode(two, one, -len_diff);
    }
    
    while(len_diff > 0){
        one = one->parent;
        len_diff--;
    }
    
    while(one != two && one && two){
        one = one->parent;
        two = two->parent;
    }
    
    return one;
}

TreeNodeP* LCA_with_parent_pointer(TreeNodeP* one, TreeNodeP* two){
    if(one == NULL || two == NULL){
        return NULL;
    }
    
    int len_one = getLen(one);
    int len_two = getLen(two);
    
    return mergeNode(one, two, len_one-len_two);
}
