//
//  Has Sum Any to Any(on Root to Leaf).cpp
//  LC2016
//
//  Created by Fang Liu on 4/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree in which each node contains an integer number. Determine if there exists a path (the path can only be from one node to itself or to any of its descendants), the sum of the numbers on the path is the given target number.
 
 Examples
        5
     /    \
    2      11
         /    \
        6     14
       /
      3
 
 If target = 17, There exists a path 11 + 6, the sum of the path is target.
 If target = 20, There exists a path 11 + 6 + 3, the sum of the path is target.
 If target = 10, There does not exist any paths sum of which is target.
 If target = 11, There exists a path only containing the node 11.
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

void helper_hasSum_anyRootToLeaf(BinaryTreeNode* root, int target, vector<int> path, bool& res){
    if(root == NULL){
        return;
    }
    
    path.push_back(root->val);
    int cur_sum = 0;
    for(int i=path.size(); i>=0; --i){
        cur_sum = cur_sum + path[i];
        if(cur_sum == target){
            res = true;
        }
    }
    
    helper_hasSum_anyRootToLeaf(root->left, target, path, res);
    helper_hasSum_anyRootToLeaf(root->right, target, path, res);
    
    path.pop_back();
}

bool has_pathSum_anyRootToLeaf(BinaryTreeNode* root, int target){
    if(root == NULL){
        return false;
    }
    
    vector<int> path;
    bool res = false;
    helper_hasSum_anyRootToLeaf(root, target, path, res);
    return res;
}