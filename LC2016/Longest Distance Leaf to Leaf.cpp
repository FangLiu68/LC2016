//
//  Longest Distance Leaf to Leaf.cpp
//  LC2016
//
//  Created by Fang Liu on 4/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node contains an integer number. The diameter is defined as the longest distance from one leaf node to another leaf node. The distance is the number of nodes on the path.
 If there does not exist any such paths, return 0.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

int helper_diameterBT(BinaryTreeNode* root, int& max_len);

int diameter_BT(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    int max_len = 0;
    helper_diameterBT(root, max_len);
    return max_len;
}

int helper_diameterBT(BinaryTreeNode* root, int& max_len){
    if(root == NULL){
        return 0;
    }
    
    int left_len = helper_diameterBT(root->left, max_len);
    int right_len = helper_diameterBT(root->right, max_len);
    int cur_len = left_len + right_len + 1;
    if(root->left && root->right && cur_len > max_len){
        max_len = cur_len;
    }
    
    return max(left_len, right_len) + 1;
}