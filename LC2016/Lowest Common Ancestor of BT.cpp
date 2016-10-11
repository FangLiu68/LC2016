//
//  Lowest Common Ancestor.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/* 
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 
 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
        7    4
 For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

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

