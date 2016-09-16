//
//  Lowest Common Ancestor.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// find the lowest common ancestor of a given binary tree

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* LCA(BinaryTreeNode* root, BinaryTreeNode* a, BinaryTreeNode* b){
    // base case
    if(root == NULL){
        return NULL;
    }
    
    if(root == a || root == b){
        return root;
    }
    
    BinaryTreeNode* left = LCA(root->left, a, b);
    BinaryTreeNode* right = LCA(root->right, a, b);
    
    if(left && right){
        return root;
    }else{
        return left ? left : right;
    }
}

