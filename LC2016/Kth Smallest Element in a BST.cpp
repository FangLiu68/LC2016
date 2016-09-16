//
//  Kth Smallest Element in a BST.cpp
//  LC2016
//
//  Created by Fang Liu on 8/9/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary search tree, write a fuction kthSmallest to find the kth smallest element in it.
 
 Note:
 You may assume k is always valid, 1 <= k <= BST's total elements.
 
 Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize teh kthSmallest routine?
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

struct BinaryTreeNode2{
    int val;
    int numLeftChildren;
    BinaryTreeNode2* left;
    BinaryTreeNode2* right;
    BinaryTreeNode2(int v, int leftChildren) : val(v), numLeftChildren(leftChildren), left(NULL), right(NULL){}
};

int kthSmallest(BinaryTreeNode2* root, int k){
    if(root == NULL){
        return 0;
    }
    
    if(root->numLeftChildren == k-1){
        return root->val;
    }else if(root->numLeftChildren > k-1){
        return kthSmallest(root->left, k);
    }else{
        return kthSmallest(root->right, k-1-root->numLeftChildren);
    }
}