//
//  BinaryTree.h
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h
#include <iostream>
using namespace std;
struct BinaryTreeNode{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int value) : val(value), left(NULL), right(NULL){}
};

#endif /* BinaryTree_h */
