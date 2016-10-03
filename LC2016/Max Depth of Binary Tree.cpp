//
//  Max Depth of Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 9/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, find its maximum depth.
 
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 use DFS post order traverse
 time O(N)
 space O(N) for recursion stack use
 */
int maxDepth(BinaryTreeNode* root) {
    if(root == NULL){
        return 0;
    }
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    
    return max(left, right) + 1;
}
