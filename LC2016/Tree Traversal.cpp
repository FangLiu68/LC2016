//
//  Tree Traversal.cpp
//  LC2016
//
//  Created by Fang Liu on 3/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"

void preOrderTraversal(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    
    cout << root->val << " ";
    
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

void posOrderTraversal(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    
    posOrderTraversal(root->left);
    posOrderTraversal(root->right);
    cout << root->val << " ";
}