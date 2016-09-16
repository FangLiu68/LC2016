//
//  Right View Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 4/12/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
 For example:
 Given the following binary tree,
 1            <---
 /   \
 2     3         <---
 \     \
 5     4       <---
 You should return [1, 3, 4].
 */

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

void helper(BinaryTreeNode* root, int& pre_level, int cur_level, vector<int>& res);

vector<int> rightSideView(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    int pre_level = 0;
    int cur_level = 1;
    helper(root, pre_level, cur_level, res);
    return res;
}

void helper(BinaryTreeNode* root, int& pre_level, int cur_level, vector<int>& res){
    if(root == NULL){
        return;
    }
    
    if(cur_level > pre_level){
        pre_level = cur_level;
        res.push_back(root->val);
    }
    
    helper(root->right, pre_level, cur_level+1, res);
    helper(root->left, pre_level, cur_level+1, res);
}