//
//  Invert Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 4/12/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Invert a binary tree
        4
      /   \
     2     7
    / \   / \
   1   3 6   9
 to
        4
      /   \
     7     2
    / \   / \
   9   6 3   1
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTreeNode* invertTree(BinaryTreeNode* root) {
    if(root == NULL){
        return NULL;
    }
    
    BinaryTreeNode* left = invertTree(root->left);
    BinaryTreeNode* right = invertTree(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
}
/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(4);
    BinaryTreeNode* node1 = new BinaryTreeNode(7);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    root->left = node1;
    root->right = node2;
    BinaryTreeNode* res = invertTree(root);
    cout << res->val << endl;
    cout << res->left->val << endl;
    cout << res->right->val << endl;
    return 0;
}*/
