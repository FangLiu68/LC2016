//
//  Get Keys in BST in Given Range.cpp
//  LC2016
//
//  Created by Fang Liu on 4/9/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Get the list of keys in a given binary search tree in a given range [min, max] in ascending order, both min and max are inclusive.
 
 Corner Cases
 What if there are no keys in the given range? return an empty list in this case.
 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

void helper_getKeysInBST(BinaryTreeNode* root, int min, int max, vector<int>& res){
    if(root == NULL){
        return ;
    }
    
    if(root->val > min){
        helper_getKeysInBST(root->left, min, max, res);
    }
    
    if(root->val >= min && root->val <= max){
        res.push_back(root->val);
    }
    
    if(root->val < max){
        helper_getKeysInBST(root->right, min, max, res);
    }
}

vector<int> get_keys_in_BST(BinaryTreeNode* root, int min, int max){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    
    helper_getKeysInBST(root, min, max, res);
    
    return res;
}