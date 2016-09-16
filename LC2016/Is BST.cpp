//
//  Is BST.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"

bool helper_isBST(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return true;
    }
    
    if(root->val <= min || root->val >= max){
        return false;
    }
    
    int left = helper_isBST(root->left, min, root->val);
    int right = helper_isBST(root->right, root->val, max);
    
    return left && right;
}

bool isBST(BinaryTreeNode* root){
    if(root == NULL){
        return true;
    }
    int min = INT_MIN;
    int max = INT_MAX;
    
    return helper_isBST(root, min, max);
}