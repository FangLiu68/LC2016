//
//  Binary Tree Maximum Path Sum.cpp
//  LC2016
//
//  Created by Fang Liu on 9/29/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, find the maximum path sum.
 For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
 
 For example:
 Given the below binary tree,
     1
    / \
   2   3
 Return 6.
 */

/*
 we want to get the max path sum from any node to any node.
 we will use DFS pos order traverse to solve this problem.
 for each node, we check the current max path sum including left subtree and right subtree after its post order traverse.
 only when the subtree's value is larger than 0, we will add it to the current sum. 
 and update the global max sum each time we calculate the current sum.
 when we pass value to upper level, we also want to include the current node's subtree only when they are larger than 0.

 time O(N)
 space O(N) for recursion stack use
 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

int helper_maxPathSum(BinaryTreeNode* root, int& res);
int maxPathSum(BinaryTreeNode* root){
    if(root == NULL) return INT_MIN;
    int res = INT_MIN;
    helper_maxPathSum(root, res);
    return res;
}

int helper_maxPathSum(BinaryTreeNode* root, int& res){
    if(root == NULL) return 0;
    
    int left = helper_maxPathSum(root->left, res);
    int right = helper_maxPathSum(root->right, res);
    left = left>0? left:0;
    right = right>0 ? right:0;
    int cur = root->val + left + right;
    res = max(res, cur);
    
    return max(left, right) + root->val;
}
