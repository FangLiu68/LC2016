//
//  Binary Tree Paths.cpp
//  LC2016
//
//  Created by Fang Liu on 10/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a binary tree, return all root-to-leaf paths.
 For example, given the following binary tree:
    1
  /   \
 2     3
  \
   5
 All root-to-leaf paths are:
 ["1->2->5", "1->3"]
 */

#include "BinaryTree.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/*
 use DFS to solve this problem.
 pass down <path> from top to bottom.
 each time before we return back to upper level, we need to pop out the node we just pushed on this level.
 when we reach the leaf node, we will push the path into a collector.
 time: O(N)
 space: O(logN) for recursion stack use
 */

void findPath(BinaryTreeNode* root, vector<int>& path, vector<vector<int>>& allPaths){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        path.push_back(root->val);
        allPaths.push_back(path);
        path.pop_back();
        return;
    }
    
    path.push_back(root->val);
    findPath(root->left, path, allPaths);
    findPath(root->right, path, allPaths);
    path.pop_back();
}

vector<string> get_str_format(vector<vector<int>> allPaths){
    vector<string> res;
    stringstream ss;
    for(int i=0; i<allPaths.size(); ++i){
        //stringstream ss;
        for(int j=0; j<allPaths[i].size(); ++j){
            ss << allPaths[i][j];
            if(j < allPaths[i].size() - 1){
                ss << "->";
            }
        }
        res.push_back(ss.str());
        ss.str(""); // clear stringstream's content
    }
    return res;
}

vector<string> binaryTreePaths(BinaryTreeNode* root){
    vector<string> res;
    if(root == NULL) return res;
    vector<int> path;
    vector<vector<int>> allPaths;
    findPath(root, path, allPaths);
    res = get_str_format(allPaths);
    return res;
}

//=========================================================
void helper_all_Paths(BinaryTreeNode* root, vector<string>& res, string t){
    if(root->left && root->right){
        res.push_back(t);
    }
    helper_all_Paths(root->left, res, t+"->"+to_string(root->left->val));
    helper_all_Paths(root->right, res, t+"->"+to_string(root->right->val));
}

vector<string> binaryTreePathsI(BinaryTreeNode* root){
    vector<string> res;
    if(root == NULL) return res;
    string t = to_string(root->val);
    helper_all_Paths(root, res, t);
    return res;
}


/*
int main(){
    BinaryTreeNode* root = new BinaryTreeNode(1);
    BinaryTreeNode* node2 = new BinaryTreeNode(2);
    BinaryTreeNode* node3 = new BinaryTreeNode(3);
    BinaryTreeNode* node5 = new BinaryTreeNode(5);
    //BinaryTreeNode* node6 = new BinaryTreeNode(6);
    //BinaryTreeNode* node7 = new BinaryTreeNode(7);
    //BinaryTreeNode* node4 = new BinaryTreeNode(4);
    //BinaryTreeNode* node8 = new BinaryTreeNode(8);
    root->left = node2;
    root->right = node3;
    node2->right = node5;
   // node5->left = node6;
    //node5->right = node7;
    //node3->left = node4;
    //node3->right = node8;
    vector<string> res = binaryTreePaths(root);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << endl;
    }
    
    
    return 0;
}
*/

