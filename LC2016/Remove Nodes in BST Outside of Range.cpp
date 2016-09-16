//
//  Remove Nodes in BST Outside of Range.cpp
//  LC2016
//
//  Created by Fang Liu on 4/9/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Retain only the nodes in range for BST [min, max], change the structure minimized
 
 用recursion
 每一层向上返回的，都是符合条件的在[min, max]之间节点
 我们并不知道返回的这个节点 在上一层的父节点里  是左子树还是右子树
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* removeOutOfRange(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return NULL;
    }
    
    if(root->val < min){
        return removeOutOfRange(root->right, min, max);
    }else if(root->val > max){
        return removeOutOfRange(root->left, min, max);
    }else{
        root->left = removeOutOfRange(root->left, min, max);
        root->right = removeOutOfRange(root->right, min, max);
        return root;
    }
}


BinaryTreeNode* removeOutOfRange1(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return NULL;
    }
    
    BinaryTreeNode* go_left = removeOutOfRange1(root->left, min, max);
    BinaryTreeNode* go_right = removeOutOfRange1(root->right, min, max);
    
    
    if(root->val < min){
        return go_right;
    }else if(root->val > max){
        return go_left;
    }else{
        root->left = go_left;
        root->right = go_right;
        return root;
    }
}