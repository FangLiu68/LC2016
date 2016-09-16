//
//  Max Sum Leaf to Leaf.cpp
//  LC2016
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int helper_maxSumLeafToLeaf(BinaryTreeNode* root, int& res);

int maxPathSum_LeafToLeaf(BinaryTreeNode* root) {
    if(root == NULL){
        return INT_MIN;
    }
    
    int res = INT_MIN;
    helper_maxSumLeafToLeaf(root, res);
    return res;
}

int helper_maxSumLeafToLeaf(BinaryTreeNode* root, int& res){
    if(root == NULL){
        return 0;
    }
    
    int left = helper_maxSumLeafToLeaf(root->left, res);
    int right = helper_maxSumLeafToLeaf(root->right, res);
    
    int cur_sum = left + right + root->val;
    if(cur_sum > res && root->left!=NULL && root->right!=NULL){
        res = cur_sum;
    }
    
    if(root->left == NULL){
        return right + root->val;
    }else if(root->right == NULL){
        return left + root->val;
    }else{
        return max(left, right) + root->val;
    }
}