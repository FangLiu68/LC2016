//
//  Print BST Keys in Given Range.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree, print all the keys of tree in range k1 to k2. eg, print all x such that k1<=x<=k2 and x is a key of given BST. Print all the keys in an increasing order.
 */

#include "BinaryTree.h"

void printRange(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return;
    }
    
    if(root->val > min){
        printRange(root->left, min, max);
    }
    
    if(root->val >= min && root->val <= max){
        cout << root->val << " ";
    }
    
    if(root->val < max)
    {
        printRange(root->right, min, max);
    }
}