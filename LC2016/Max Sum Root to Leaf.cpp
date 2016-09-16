//
//  Max Sum Root to Leaf.cpp
//  LC2016
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the maximum path cost for all paths from leaf to root in a Binary Tree
 Given a Binary Tree, find the maximum sum path from a leaf to root. For example, in the following tree, there are three leaf to root paths 8->-2->10, -4->-2->10 and 7->10. The sums of these three paths are 16, 4 and 17 respectively. The maximum of them is 17 and the path for maximum is 7->10.
            10
        /      \
      -2        7
    /   \
   8     -4
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

void helper_pathSum_RootToLeaf(BinaryTreeNode* root, int prefix, int& res){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        res = max(prefix + root->val, res);
        return;
    }
    
    helper_pathSum_RootToLeaf(root->left, prefix+root->val, res);
    helper_pathSum_RootToLeaf(root->right, prefix+root->val, res);
}

int pathSum_RootToLeaf(BinaryTreeNode* root){
    if(root == NULL){
        return INT_MIN;
    }
    
    int res = INT_MIN;
    helper_pathSum_RootToLeaf(root, 0, res);
    return res;
}