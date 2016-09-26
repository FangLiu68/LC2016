//
//  Level Order Traverse Binary Tree.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Get the list of list of keys in a given binary tree layer by layer. Each layer is represented by a list of keys and the keys are traversed from left to right.
 Examples
        5
     /    \
    3       8
  /   \      \
 1     4       11
 the result is [ [5], [3, 8], [1, 4, 11] ]
 Corner Cases
 What if the binary tree is null? Return an empty list of list in this case
 */

#include "BinaryTree.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
 when should we change layer to the next?
 What you only need to do is to store the queue.size() into a local variable
 while(!queue.empty()){
    int q_size = queue.size();
    for(int i = 0; i < q_size; ++i){
        // print every single node in the layer
    }
    // change layer here
 }
 
 */

/*
 Breadth First Search
 as container, only queue is first in first out, which mean it could keep the nodes visiting order
 so we use queue to contain current level's nodes
 since we need to seperate different levels, so we need to mark the current queue's size
 
 Time O(N), space O(N)
 */
vector<vector<int>> get_keys_byLevel(BinaryTreeNode* root){
    vector<vector<int>> res;
    if(root == NULL) return res;

    queue<BinaryTreeNode*> qu;
    vector<int> level;
    qu.push(root);

    while(!qu.empty()){
        int len = qu.size();
        for(int i = 0; i<len; ++i){
            BinaryTreeNode* cur = qu.front();
            level.push_back(cur->val);
            qu.pop();
            if(cur->left) qu.push(cur->left);
            if(cur->right) qu.push(cur->right);
        }
        res.push_back(level);
        level.clear();
    }

    return res;
}



void print_keys_level_by_level(BinaryTreeNode* root){
    if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode*> qu;
    qu.push(root);
    
    while(!qu.empty()){
        int len = qu.size();
        for(int i=0; i<len; ++i){
            BinaryTreeNode* cur = qu.front();
            qu.pop();
            if(i != 0) cout << ",";
            cout << cur->val;
            if(cur->left){
                qu.push(cur->left);
            }
            if(cur->right){
                qu.push(cur->right);
            }
        }
        cout << endl;
    }
    cout << endl;
}


/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(0);
    BinaryTreeNode* left1 = new BinaryTreeNode(1);
    BinaryTreeNode* right1 = new BinaryTreeNode(2);
    BinaryTreeNode* left2 = new BinaryTreeNode(3);
    root->left = left1;
    root->right = right1;
    right1->left = left2;
    vector<vector<int>> res = get_keys_byLevel(root);
    for(int i = 0; i<res.size(); ++i){
        for(int j=0; j<res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
