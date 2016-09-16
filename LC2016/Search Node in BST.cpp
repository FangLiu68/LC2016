//
//  Search Node in BST.cpp
//  LC2016
//
//  Created by Fang Liu on 4/8/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// search a given value from BST, and return the node which has this value

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* search_BST(BinaryTreeNode* root, int value){
    if(root == NULL){
        return NULL;
    }
    
    BinaryTreeNode* cur = root;
    while(cur){
        if(cur->val < value){
            cur = cur->right;
        }else if(cur->val > value){
            cur = cur->left;
        }else{
            return cur;
        }
    }
    
    return NULL;
}

BinaryTreeNode* search_BST_recur(BinaryTreeNode* root, int value){
    if(root == NULL){
        return NULL;
    }
    
    if(root->val < value){
        return search_BST_recur(root->right, value);
    }else if(root->val > value){
        return search_BST_recur(root->left, value);
    }else{
        return root;
    }
}