//
//  Sorted Arr to BST.cpp
//  LC2016
//
//  Created by Fang Liu on 4/13/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Convert a given sorted array to binary search tree

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* helper_arrToBST(int arr[], int left, int right);

BinaryTreeNode* arrToBST(int arr[], int len){
    if(arr == NULL || len <= 0){
        return NULL;
    }
    
    int left = 0;
    int right = len - 1;
    
    return helper_arrToBST(arr, left, right);
}

BinaryTreeNode* helper_arrToBST(int arr[], int left, int right){
    if(left > right){
        return NULL;
    }
    
    int mid = left + (right-left)/2;
    BinaryTreeNode* root = new BinaryTreeNode(mid);
    root->left = helper_arrToBST(arr, left, mid-1);
    root->right = helper_arrToBST(arr, mid+1, right);
    
    return root;
}