//
//  Get Height of BT.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include "BinaryTree.h"

/*
 Tree的题目容易和recurison结合
 base case: the null pointer under the leaf node
 本题：从下往上返回值
 */

// time complexity O(N)
// N is the total number of codes in the subtree rooted at "root"
int getHeight(BinaryTreeNode* root){
    if(root == NULL) return 0;
    
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    
    return max(left, right) + 1;
}

