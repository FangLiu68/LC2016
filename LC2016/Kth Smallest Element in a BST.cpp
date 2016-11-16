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
#include <vector>
using namespace std;

/*
 in order traverse all nodes in tree, get the kth nodes in results.
 time: O(N)
 space: O(N)
 */
void inorder_traversal(BinaryTreeNode* root, vector<int>& nodes);
int kthSmallest(BinaryTreeNode* root, int k) {
    if(root == NULL){
        throw invalid_argument("out of boundary");
    }
    vector<int> nodes;
    inorder_traversal(root, nodes);
    return nodes[k-1];
}

void inorder_traversal(BinaryTreeNode* root, vector<int>& nodes){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left, nodes);
    nodes.push_back(root->val);
    inorder_traversal(root->right, nodes);
}

//============================================================

/*
 modify the tree node structure
 add one value to record each node's left subtree's nodes count
 if current node's left subtree nodes count == k-1, we find the result
 else if the count > k-1, the result could only be exist in its left subtree
 else we go visit the right subtree.
 time: O(logN)
 space: O(logN) for recursion stack use
 */
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
