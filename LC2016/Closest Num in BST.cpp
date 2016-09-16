//
//  Find Node Closest to Target.cpp
//  LC2016
//
//  Created by Fang Liu on 4/7/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// find a node whose value is closest to the target value

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. if the cur node value < target value
    compare the diff of cur node value with the target value, update if it is closer; go to the right child node
 2. if the cur node value > target value
    compare the diff of cur node value with the target value, update if it is closer; go to the left child node
 */

int closest_node_in_BST(BinaryTreeNode* root, int target){
    if(root == NULL){
        return INT_MIN;
    }
    
    int min_diff = INT_MAX;
    BinaryTreeNode* res = root;
    
    while(root){
        int cur_diff = abs(root->val - target);
        if(cur_diff < min_diff){
            min_diff = cur_diff;
            res = root;
        }
        
        if(root->val < target){
            root = root->right;
        }else if(root->val > target){
            root = root->left;
        }else{
            return root->val;
        }
    }
    
    return res->val;
}