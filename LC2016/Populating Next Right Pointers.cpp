//
//  Populating Next Right Pointers.cpp
//  LC2016
//
//  Created by Fang Liu on 9/21/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree

 struct TreeLinkNode {
 TreeLinkNode *left;
 TreeLinkNode *right;
 TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

 Initially, all next pointers are set to NULL.

 Note:

 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
        1
      /  \
     2    3
    / \  / \
   4  5  6  7
 After calling your function, the tree should look like:
        1 -> NULL
      /  \
     2 -> 3 -> NULL
    / \  / \
   4->5->6->7 -> NULL
 */

#include "BinaryTree.h"
#include <queue>
#include <iostream>
using namespace std;

struct TreeLinkNode{
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
};

/*
 Method 1:
 level order traverse.
 we add a new pointer tail pointing to the front node of the queue.
 if current queue only has one node, do nothing.
 else, set tail pointing to the current front node of queue, and move tail to next in next round.
 
 Time O(N), space O(N)
 */
void connect1(TreeLinkNode *root) {
    if(root == NULL){
        return;
    }

    queue<TreeLinkNode*> qu;
    qu.push(root);

    while(!qu.empty()){
        int size = qu.size();
        TreeLinkNode* tail = NULL;
        for(int i=0; i<size; ++i){
            TreeLinkNode* cur = qu.front();
            qu.pop();
            if(i == 0){
                tail = cur;
            }else{
                tail->next = cur;
                tail = tail->next;
            }

            if(cur->left){
                qu.push(cur->left);
            }
            if(cur->right){
                qu.push(cur->right);
            }
        }
    }
}

/*
 Method 2:
 remember: this is a perfect tree, which means each node either a leaf node, or it has both left child and right child.
 so there should be two direction's iterations:
 1. levels from top to down:
    start from root, end until current node's left child is NULL (next level are all NULL, they don't have next pointer, and the current level's next pointer are already been setted by upper level's round)
 2. for each level, from left to right"
    start from the most left node, and end until the current node is NULL
 
 Time O(N), space O(1)
 */
void connect2(TreeLinkNode *root) {
    if(root == NULL) return;
    TreeLinkNode* pre = root;
    TreeLinkNode* cur = NULL;

    while(pre->left){
        cur = pre;
        while(cur){
            cur->left->next = cur->right;
            if(cur->next){
                cur->right->next = cur->next->left;
            }
            cur = cur->next;
        }
        pre = pre->left;
    }
}

