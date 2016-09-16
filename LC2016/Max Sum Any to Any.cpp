//
//  Max Sum Any to Any.cpp
//  LC2016
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node contains an integer number. Find the maximum possible sum from any node to any node (the start node and the end node can be the same).
 
 Assumptions
 ​The root of the given binary tree is not null
 Examples
        -1
      /    \
     2      11
           /   \
          6     -14
 
 one example of paths could be -14 -> 11 -> -1 -> 2
 another example could be the node 11 itself
 The maximum path sum in the above binary tree is 6 + 11 + (-1) + 2 = 18
 */


#include "BinaryTree.h"
#include <iostream>
using namespace std;

int helper_maxPath_sum_anyToAny(BinaryTreeNode* root, int& res);

int maxPathSum_anyToAny(BinaryTreeNode* root) {
    if(root == NULL) return INT_MIN;
    int res = INT_MIN;
    helper_maxPath_sum_anyToAny(root, res);
    return res;
}

int helper_maxPath_sum_anyToAny(BinaryTreeNode* root, int& res){
    if(root == NULL){
        return 0;
    }
    
    int left_cost = helper_maxPath_sum_anyToAny(root->left, res);
    int right_cost = helper_maxPath_sum_anyToAny(root->right, res);
    
    int left_chose = left_cost>0 ? left_cost : 0;
    int right_chose = right_cost>0 ? right_cost : 0;
    int cur_cost = left_chose + right_chose + root->val;
    res = max(res, cur_cost);
    
    return max(left_chose, right_chose) + root->val;
}