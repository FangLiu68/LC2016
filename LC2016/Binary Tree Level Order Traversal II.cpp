//
//  Binary Tree Level Order Traversal II.cpp
//  LC2016
//
//  Created by Fang Liu on 11/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, return teh bottom-up level order traversal of its nodes' values. (from left to right, level by level from leaf to root).
 For example:
 Given binary tree [3, 9, 20, null, null, 15, 7]
        3
       / \
      9  20
        /  \
       15   7
 return its bottom-up level order traversal as:
 [
 [15,7],
 [9,20],
 [3]
 ]
 */

#include "BinaryTree.h"
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> levelOrderBottom(BinaryTreeNode* root){
    vector<vector<int>> res;
    vector<int> level;
    if(root == NULL) return res;
    
    queue<BinaryTreeNode*> qu;
    qu.push(root);
    
    while(!qu.empty()){
        int len = qu.size();
        for(int i=0; i<len; ++i){
            BinaryTreeNode* cur = qu.front();
            qu.pop();
            level.push_back(cur->val);
            if(cur->left) qu.push(cur->left);
            if(cur->right) qu.push(cur->right);
        }
        res.push_back(level);
        level.clear();
    }
    
    reverse(res.begin(), res.end());
    return res;
}
