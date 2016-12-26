//
//  postOrder Traverse.cpp
//  LC2016
//
//  Created by Fang Liu on 9/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

//
//  post_order traverse.cpp
//  LaiOffer
//
//  Created by Fang Liu on 2/4/15.
//  Copyright (c) 2015 Fang Liu. All rights reserved.
//

/*
 Implement an iterative, post-order traversal of a given binary tree, return the list of keys of each node in the tree as it is post-order traversed.
 Examples
            5
         /    \
        3      8
      /   \     \
     1    4      11
 Post-order traversal is [1, 4, 3, 11, 8, 5]
 Corner Cases
 What if the given binary tree is null? Return an empty list in this case
 */

#include "BinaryTree.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 post order traversal, 想要先返回每一个NODE的左孩子，再返回右孩子，最后返回自身。
 只能用两个stack来做
 从左到右level order traversal的同时将stack1头结点的左右孩子放在stack1中
 并将头结点pop出后放入stack2中
 stack2里面的值就是post order最后结果
 */
vector<int> postOrder_iter(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL){
        return res;
    }
    stack<BinaryTreeNode*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        BinaryTreeNode* cur = s1.top();
        s1.pop();
        s2.push(cur);
        if(cur->left) s1.push(cur->left);
        if(cur->right) s1.push(cur->right);
    }
    while(!s2.empty()){
        BinaryTreeNode* cur = s2.top();
        s2.pop();
        res.push_back(cur->val);
    }
    return res;
}

//==========================================================
void helper_post(BinaryTreeNode* root, vector<int> &res);
vector<int> post_order_recur(BinaryTreeNode* root) {
    vector<int> res;
    if(root == NULL) return res;
    helper_post(root, res);
    return res;
}
void helper_post(BinaryTreeNode* root, vector<int> &res){
    if(root == NULL) return;
    helper_post(root->left, res);
    helper_post(root->right, res);
    res.push_back(root->val);
}
