//
//  Identical Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Check if two given binary trees are identical. 
 Identical means the equal valued keys are at the same position in the two binayr trees
 */

#include "BinaryTree.h"

bool identical_BT(BinaryTreeNode* root1, BinaryTreeNode* root2){
    // base
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->val != root2->val){
        return false;
    }
    
    int left = identical_BT(root1->left, root2->left);
    int right = identical_BT(root1->right, root2->right);
    
    return left && right;
}