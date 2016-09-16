//
//  Get Left Subtree Nodes.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// How to store how many nodes in each node's left-subtree?

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    int left_subtree_nodes;
    TreeNode(int v) : val(v), left(NULL), right(NULL), left_subtree_nodes(0){}
};

// 也是从下往上返回值
int store_leftNodes(TreeNode* root){
    // base case
    if(root == NULL){
        return 0;
    }
    
    // what do u expect from your left and right children
    int num_leftNodes = store_leftNodes(root->left);
    int num_rightNodes = store_leftNodes(root->right);
    
    // what do u want to do in current layer
    root->left_subtree_nodes = num_leftNodes;
    
    // what do u want to report to your parent
    return num_leftNodes + num_rightNodes + 1;
}