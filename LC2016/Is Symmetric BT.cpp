//
//  Is Symmetric BT.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// judge wheterh a binary tree is symmetric

#include "BinaryTree.h"

// time complexity O(N)
bool helper_symmetric(BinaryTreeNode* left, BinaryTreeNode* right){
    // base case
    if(left == NULL && right == NULL){
        return true; // return true until find node under leaf node
    }else if(left == NULL || right == NULL){
        return false; // return false early (check from top to bottom, on the way to leaf node)
    }else if(left->val != right->val){
        return false;
    }

    // recursive rule
    bool inside = helper_symmetric(left->right, right->left);
    bool outside = helper_symmetric(left->left, right->right);
    
    return inside && outside;
}
