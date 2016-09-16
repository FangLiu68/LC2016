
//
//  Count Complete Binary Tree Nodes.cpp
//  LC2016
//
//  Created by Fang Liu on 4/15/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a complete binary tree, count the number of nodes.
 
 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int left_height(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->left;
    }
    return res;
}

int right_height(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->right;
    }
    return res;
}

int countNodes(BinaryTreeNode* root){
    if(root == NULL) return 0;
    
    int left = left_height(root);
    int right = right_height(root);
    
    if(left == right){
        return (1 << left) - 1;
    }else{
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}