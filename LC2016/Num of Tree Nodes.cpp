//
//  Num of Tree Nodes.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// get the number of tree nodes

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// 和get height of BT一样，都是从下往上返回值
int getNumOfTreeNodes(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int left = getNumOfTreeNodes(root->left);
    int right = getNumOfTreeNodes(root->right);
    
    return left + right + 1;
}