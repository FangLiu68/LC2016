//
//  Border View of Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 5/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"
#include <vector>
#include <iostream>
using namespace std;

void borderView(BinaryTreeNode* root, int flag1, int flag2){
    if(root == NULL){
        return;
    }
    if(flag1 == 0 || (root->left==NULL && root->right==NULL)){
        cout << root->val << " ";
    }
    borderView(root->left, flag1, 1);
    borderView(root->right, 1, flag2);
    if(flag2==0 && (root->left!=NULL && root->right!=NULL) && flag1==1){
        cout << root->val << " ";
    }
}

void border_view(BinaryTreeNode* root){
    borderView(root, 0, 0);
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(5);
    BinaryTreeNode* node1 = new BinaryTreeNode(1);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node4 = new BinaryTreeNode(4);
    BinaryTreeNode* node9 = new BinaryTreeNode(9);
    BinaryTreeNode* node8 = new BinaryTreeNode(8);
    BinaryTreeNode* node11 = new BinaryTreeNode(11);
    
    root->left = node1;
    node1->right = node3;
    node3->right = node4;
    root->right = node9;
    node9->left = node8;
    node9->right = node11;
    
    border_view(root);
    cout << endl;
    return 0;
}
*/