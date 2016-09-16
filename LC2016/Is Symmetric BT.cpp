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
bool helper_symmetric(BinaryTreeNode* one, BinaryTreeNode* two){
    if(one == NULL && two == NULL){
        return true;
    }else if(one == NULL || two == NULL){
        return false;
    }else if(one->val != two->val){
        return false;
    }
    
    bool inside = helper_symmetric(one->right, two->left);
    bool outside = helper_symmetric(one->left, two->right);
    
    return inside && outside;
}