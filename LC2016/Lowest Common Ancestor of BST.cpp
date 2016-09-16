//
//  Lowest Common Ancestor of BST.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// find the lowest common ancestor of a binary search tree

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// 既然是BST，我们就可以利用值的大小关系来做
BinaryTreeNode* LCA_BST(BinaryTreeNode* root, BinaryTreeNode* a, BinaryTreeNode* b){
    // base case
    if(root == NULL){
        return NULL;
    }
    
    if(root == a || root == b){
        return root;
    }
    
    if(max(a->val, b->val) < root->val){
        return LCA_BST(root->left, a, b);
    }else if(min(a->val, b->val) > root->val){
        return LCA_BST(root->right, a, b);
    }else{
        return root;
    }
}