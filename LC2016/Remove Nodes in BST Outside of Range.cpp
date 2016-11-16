//
//  Remove Nodes in BST Outside of Range.cpp
//  LC2016
//
//  Created by Fang Liu on 4/9/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Retain only the nodes in range for BST [min, max], change the structure minimized
 
 用recursion
 每一层向上返回的，都是符合条件的在[min, max]之间节点
 我们并不知道返回的这个节点 在上一层的父节点里  是左子树还是右子树
 
                5
            /       \
           3         9
        /     \     /   \
       1      4    6     10
 [4, 9]
*/

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 1. node's key is in range -> do nothing
 2. node's key is out of range:
    a. key > max ->repalce node with left child
    b. key < min -> replace node with right child
 time O(N)
 space O(logN) for recursion stack
 */
BinaryTreeNode* removeOutOfRange(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return NULL;
    }
    
    if(root->val < min){
        return removeOutOfRange(root->right, min, max);
    }else if(root->val > max){
        return removeOutOfRange(root->left, min, max);
    }else{
        root->left = removeOutOfRange(root->left, min, max);
        root->right = removeOutOfRange(root->right, min, max);
        return root;
    }
}


BinaryTreeNode* removeOutOfRange1(BinaryTreeNode* root, int min, int max){
    if(root == NULL){
        return NULL;
    }
    
    BinaryTreeNode* go_left = removeOutOfRange1(root->left, min, max);
    BinaryTreeNode* go_right = removeOutOfRange1(root->right, min, max);
    
    
    if(root->val < min){
        return go_right;
    }else if(root->val > max){
        return go_left;
    }else{
        root->left = go_left;
        root->right = go_right;
        return root;
    }
}

void printNode_inOrder(BinaryTreeNode* root){
    if(root == NULL) return;
    printNode_inOrder(root->left);
    cout << root->val << " ";
    printNode_inOrder(root->right);
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node9 = new BinaryTreeNode(9);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node6 = new BinaryTreeNode(6);
    BinaryTreeNode* node10 = new BinaryTreeNode(10);
    root->left = node3;
    root->right = node9;
    node3->left = node1;
    node3->right = node4;
    node9->left = node6;
    node9->right = node10;
    int min = 4;
    int max = 9;
    BinaryTreeNode* res = removeOutOfRange1(root, min, max);
    printNode_inOrder(res);
    cout << endl;
    return 0;
}
*/
