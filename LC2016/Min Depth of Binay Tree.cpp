//
//  Min Depth of Binay Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 11/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int minDepth(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }

    queue<BinaryTreeNode*> qu;
    qu.push(root);
    int res = 0;

    while(!qu.empty()){
        res++;
        int size = qu.size();
        for(int i=0; i<size; ++i){
            BinaryTreeNode* cur = qu.front();
            if(cur->left==NULL && cur->right==NULL){
                return res;
            }
            qu.pop();
            if(cur->left) qu.push(cur->left);
            if(cur->right) qu.push(cur->right);
        }
    }

    return res;
}


