//
//  Has Sum Root To Leaf.cpp
//  LC2016
//
//  Created by Fang Liu on 4/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
        5
       / \
      4   8
     /   / \
    11  13  4
   /  \      \
  7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;

/*
 DFS pre order traverse the tree from root to leaf.
 collect each node's value along the way (from root to leaf)
 when we reach to the leaf node, if current added result is equal to sum, then return true.
 else, we use DFS to continue pre order traverse other nodes.
 
 NOTE: 
 on the same level, our prefix sum is the same.
 eg, for node 11, when we traverse to node 7, sum = prefix + 11 + 7
     when this way doesn't work, we go back to upper level (node 11) and start to traverse to node 2, sum = prefix + 11 + 2
 
 Time O(N)
 Space O(N) (recursion use stack space)
 */

bool hasPathSum(BinaryTreeNode* root, int sum) {
    if(root == NULL) return false;
    if(root->val == sum && root->left == NULL && root->right == NULL){
        return true;
    }
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}


//======================================
void helper_hasPath(BinaryTreeNode* root, int sum, int prefix, bool& res);

bool hasPathSumI(BinaryTreeNode* root, int sum) {
    if(root == NULL) return false;
    bool res = false;
    helper_hasPath(root, sum, 0, res);
    return res;
}

void helper_hasPath(BinaryTreeNode* root, int sum, int prefix, bool& res){
    if(res == true) return;
    if(root == NULL) return;
    
    if(root->left == NULL && root->right == NULL){
        if(prefix + root->val == sum){
            res = true;
            return;
        }
    }
    
    helper_hasPath(root->left, sum, prefix+root->val, res);
    helper_hasPath(root->right, sum, prefix+root->val, res); // on this level, prefix doesn't change
}

//========================
void helper(BinaryTreeNode* root, vector<int>& path, int sum, bool& res);
bool hasPathSumII(BinaryTreeNode* root, int sum) {
    if(root == NULL) return false;
    vector<int> path;
    bool res = false;
    helper(root, path, sum, res);
    return res;
}

void helper(BinaryTreeNode* root, vector<int>& path, int sum, bool& res){
    if(res == true){
        return;
    }
    if(root == NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        path.push_back(root->val);
        int cur = 0;
        for(int i=0; i<path.size(); ++i){
            cur += path[i];
        }
        if(cur == sum){
            res = true;
            return;
        }else{
            path.pop_back();
            return;
        }
    }
    
    path.push_back(root->val);
    helper(root->left,path, sum, res);
    helper(root->right, path, sum, res);
    path.pop_back();
}
