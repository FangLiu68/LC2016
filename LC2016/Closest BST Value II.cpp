//
//  Closest BST Value II.cpp
//  LC2016
//
//  Created by Fang Liu on 9/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 Note:
 Given target value is a floating point.
 You may assume k is always valid, that is: k ≤ total nodes.
 You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 */

#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

vector<int> inOrder_iter(BinaryTreeNode* root){
    vector<int> res;
    if(root == NULL) return res;
    stack<BinaryTreeNode*> stk;
    BinaryTreeNode* cur = root;
    while(cur || !stk.empty()){
        if(cur){
            stk.push(cur);
            cur = cur->left;
        }else{
            BinaryTreeNode* tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            cur = tmp->right;
        }
    }
    return res;
}


queue<int> closest_BST_value(BinaryTreeNode* root, int k){
    queue<int> res;
    if(root == NULL) return res;

    stack<BinaryTreeNode*> stk;
    BinaryTreeNode* cur = root;

    while(cur || !stk.empty()){
        if(cur){
            stk.push(cur);
            cur = cur->left;
        }else{
            BinaryTreeNode* temp = stk.top();
            stk.pop();
            if(res.size() == k){
                
            }
            res.push(temp->val);
        }
    }
    return res;
}
