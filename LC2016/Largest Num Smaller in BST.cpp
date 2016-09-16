//
//  Largest Num Smaller in BST.cpp
//  LC2016
//
//  Created by Fang Liu on 4/7/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 In a binary search tree, find the node containing the largest number smaller than the given target number.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int largestSmaller(BinaryTreeNode* root, int target){
    if(root == NULL){
        return INT_MIN;
    }
    
    BinaryTreeNode* res = NULL;
    while(root){
        if(root->val >= target){
            root = root->left;
        }else{
            res = root;
            root = root->right;
        }
    }
    
    if(!res){
        return INT_MIN;
    }else{
        return res->val;
    }
}