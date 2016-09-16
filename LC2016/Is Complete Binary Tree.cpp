//
//  Is Complete Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 4/15/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Check if a given binary tree is completed. A complete binary tree is one in which every level of the binary tree is completely filled except possibly the last level. Furthermore, all nodes are as far left as possible.
 
 Examples
 
 5
 /    \
 3      8
 /   \
 1      4
 is completed.
 
 5
 /    \
 3       8
 /   \       \
 1      4      11
 is not completed.
 
 Corner Cases
 What if the binary tree is null? Return true in this case.
 How is the binary tree represented?
 
 We use the level order traversal sequence with a special symbol "#" denoting the null node.
 
 For Example:
 The sequence [1, 2, 3, #, #, 4] represents the following binary tree:
 1
 /   \
 2     3
 /
 4
 */

#include "BinaryTree.h"
#include <iostream>
#include <queue>
using namespace std;

bool is_completeBT(BinaryTreeNode* root){
    if(root == NULL){
        return true;
    }
    
    queue<BinaryTreeNode*> qu;
    qu.push(root);
    bool flag = false;
    
    while(!qu.empty()){
        BinaryTreeNode* cur = qu.front();
        qu.pop();
        
        if(cur->left == NULL){
            flag = true;
        }else if(flag == true){
            return false;
        }else{
            qu.push(cur->left);
        }
        
        if(cur->right == NULL){
            flag = true;
        }else if(flag == true){
            return false;
        }else{
            qu.push(cur->right);
        }
    }
    
    return true;
}
