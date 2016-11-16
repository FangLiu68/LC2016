
//
//  Count Complete Binary Tree Nodes.cpp
//  LC2016
//
//  Created by Fang Liu on 4/15/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a complete binary tree, count the number of nodes.
 
 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. left subtree height == right subtree height
    a. left subtree is full
    b. do recursion on right subtree
 2. left subtree height != right subtree height
    a. right subtree is full
    b. do recursion on left subtree
 NOTE: 1 << n 意思是2的n次方
 总节点数 = 
        1（根节点数）+
        2^h-1 (full subtree节点数，h为full subtree高度，h从1开始) +
        recursion
 time:
    1. only go left or right. => traverse logN
    2. calculate depth every time => logN
    => total time O((logN)^2)
 space:
    logN for recursion stack use
 */

int get_depth(BinaryTreeNode* root);
int countNodes(BinaryTreeNode* root) {
    if(root == NULL) return 0;
    int left_depth = get_depth(root->left);
    int right_depth = get_depth(root->right);
    if(left_depth == 0) return 1;
    if(left_depth == right_depth){
        return 1 + (1<<left_depth)-1 + countNodes(root->right);
    }else{
        return 1 + (1<<right_depth)-1 + countNodes(root->left);
    }
}

int get_depth(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->left;
    }
    return res;
}


//=======================================================
int left_height(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->left;
    }
    return res;
}

int right_height(BinaryTreeNode* root){
    int res = 0;
    while(root){
        res++;
        root = root->right;
    }
    return res;
}

int countNodesI(BinaryTreeNode* root){
    if(root == NULL) return 0;
    
    int left = left_height(root);
    int right = right_height(root);
    
    if(left == right){
        return (1 << left) - 1;
    }else{
        return countNodesI(root->left) + countNodesI(root->right) + 1;
    }
}
/*
int main(){
    int res = 1 << 1;
    cout << res << endl;
    return 0;
}
*/
