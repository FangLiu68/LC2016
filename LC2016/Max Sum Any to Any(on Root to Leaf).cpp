//
//  Max Sum Any to Any(on Root to Leaf).cpp
//  LC2016
//
//  Created by Fang Liu on 4/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node contains an integer number. Find the maximum possible sum from any node to any node (the two nodes can be the same node and they can only be on the path from root to one of the leaf nodes).
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

void helper_pathSum(BinaryTreeNode* root, vector<int> path, int& max_sum){
    if(root == NULL){
        return;
    }
    
    path.push_back(root->val);
    int cur_sum = 0;
    for(int i=path.size(); i>=0; --i){
        cur_sum = cur_sum + path[i];
        max_sum = max(cur_sum, max_sum);
    }
    
    helper_pathSum(root->left, path, max_sum);
    helper_pathSum(root->right, path, max_sum);
    
    path.pop_back();
}

int maxSum_anyRootToLeaf(BinaryTreeNode* root){
    if(root == NULL){
        return INT_MIN;
    }
    vector<int> path;
    int max_sum = INT_MIN;
    helper_pathSum(root, path, max_sum);
    return max_sum;
}