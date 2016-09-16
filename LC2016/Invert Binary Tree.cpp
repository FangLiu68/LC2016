//
//  Invert Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 4/12/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Invert a binary tree
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* invertTree(BinaryTreeNode* root) {
    if(root == NULL){
        return NULL;
    }
    
    BinaryTreeNode* left = invertTree(root->left);
    BinaryTreeNode* right = invertTree(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
}