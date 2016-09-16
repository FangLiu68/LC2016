//
//  Lowest Common Ancestor of K-nary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given K nodes in a binary tree, find their lowest common ancestor.
 
 Assumptions
 K >= 2
 There is no parent pointer for the nodes in the bianry tree
 The given two nodes are guaranteed to be in the binary tree
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

BinaryTreeNode* LCA_kNodes_inBT(BinaryTreeNode* root, vector<BinaryTreeNode*> input){
    if(root == NULL){
        return NULL;
    }
    
    for(int i=0; i<input.size(); ++i){
        if(root == input[i]){
            return root;
        }
    }
    
    BinaryTreeNode* left = LCA_kNodes_inBT(root->left, input);
    BinaryTreeNode* right = LCA_kNodes_inBT(root->right, input);
    
    if(left && right){
        return root;
    }else{
        return left? left:right;
    }
}