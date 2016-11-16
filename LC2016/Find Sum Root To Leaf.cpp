//
//  Find Sum Root To Leaf.cpp
//  LC2016
//
//  Created by Fang Liu on 4/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \    / \
 7    2  5   1
 return
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

/*
Method 1:
Use container to store the nodes we visited along path, and check the sum when we reach leaf node.
Time O(N)
Space O(N)
*/
void pathSum_helper(BinaryTreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res);
vector<vector<int>> pathSum(BinaryTreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    if(root == NULL) return res;
    pathSum_helper(root, sum, path, res);
    return res;
}

void pathSum_helper(BinaryTreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->val);
        int cur = 0;
        for(int i=0; i<path.size(); ++i){
            cur += path[i];
        }
        if(cur == sum){
            res.push_back(path);
        }
        path.pop_back();
        return;
    }
    
    path.push_back(root->val);
    pathSum_helper(root->left, sum, path, res);
    pathSum_helper(root->right, sum, path, res);
    path.pop_back();
}

/*
Method 2:
Instead we add all nodes value in container, we minus the node’s value along the path when we do DFS. this could save some time.
Time O(N)
Space O(N)
*/
void pathSum_helperI(BinaryTreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res);
vector<vector<int>> pathSumI(BinaryTreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    if(root == NULL) return res;
    pathSum_helper(root, sum, path, res);
    return res;
}

void pathSum_helperI(BinaryTreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->val);
        if(root->val == sum){
            res.push_back(path);
        }
        path.pop_back();
        return;
    }
    
    path.push_back(root->val);
    pathSum_helperI(root->left, sum-root->val, path, res);
    pathSum_helperI(root->right, sum-root->val, path, res);
    path.pop_back();
}
