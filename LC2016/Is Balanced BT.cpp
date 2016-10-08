//
//  is Balanced BT.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 determine whether a binary tree is a balanced binary tree.
 
 balanced bianry tree:
 a binary tree in which the depth of the left and right subtrees of every node differ by 1 or less
 */

#include "BinaryTree.h"

/*
                    10  root                            (2 times getHeight n/2 + n/2)-->O(n)
            /                           \
     5(2 times getHeight  n/2)       15(n/2)            -->O(n)
   /               \                /   \
 3(N/4)             9(N/4)     12(N/4)  20(N/4)
 */

// time complexity O(N)
// N is all the subtree nodes that rooted at "root"
int helper_getHeight(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int left = helper_getHeight(root->left);
    int right = helper_getHeight(root->right);
    
    return max(left, right) + 1;
}

/*
 isBalancedBT的时间复杂度分析：
 大框架：isBalancedBT(root) recursively 调用自身两次isBalancedBT(root->left) 和 isBalancedBT(root->right)
 每次调用自身时，同时getHeight(root->left)，和 getHeight(root->right)
 recursively call自身的每次，都是triger程序的执行，我们可以把isBalancedBT(root->left)和isBalancedBT(root->right)的复杂度认为是1
 我们只需要知道，每次recursively call的时候，getHeight()执行了几次，执行的时间复杂度
 getHeight(node K)的时间复杂度是，以node K为根节点的子树的大小
 
 假设，以10为根节点的，整个tree的节点数目是N
 time: isBalanced(10) = getHeight(5)+getHeight(15)
 getHeight(5) use time O(N/2)
 getHeight(15) use time O(N/2)
 所以对于第一层10来说，time = O(N/2) + O(N/2) = O(N) + O(N) = O(N)
 
 对于第二层来说
 time: isBalanced(5) = getHeight(3) + getHeight(9)
 getHeight(3) use time O(N/4)
 getHeight(9) use time O(N/4)
 isBalanced(5) use time O(N/4) + O(N/4) = O(N)
 same as node 15
 so, the second level time is also O(N)
 
 and for a balanced binary tree, the level is logN
 so totally we use time O(NlogN)
 */
bool isBalancedBT(BinaryTreeNode* root){
    if(root == NULL){
        return true;
    }
    
    if(abs(helper_getHeight(root->left) - helper_getHeight(root->right)) > 1){
        return false;
    }
    
    return isBalancedBT(root->left) && isBalancedBT(root->right);
}

//=========================================================

// 老方法是，对于任意一个Node，都要算他的左右高度，这样我们就会重复算每个node的高度
// 新方法是，因为我们算高度的时候都是从leaf node的下一层触底反弹，由下往上一步步返回左右子树的高度，那么为了不想重复计算，对于每个节点，当我们算出来他的左右子树的高度时，我们直接把abs(left-right)>1的结果往上返回-1，同时当下次比较其父节点的时候，对于有-1的子树直接往上返回-1，不再计算。
// 这样我们是改进了get height of BT的方法，最后只用判断下得到的height是否是-1即可。
// 所以这个方法和get height的BIGO一样，都是O（N）
int getHeight_fast(BinaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int left = getHeight_fast(root->left);
    int right = getHeight_fast(root->right);
    
    if(abs(left - right) > 1 || left == -1 || right == -1 ){
        return -1;
    }
    
    return max(left, right) + 1;
}

int isBalancedBT_fast(BinaryTreeNode* root){
    if(root == NULL){
        return true;
    }
    
    return getHeight_fast(root) != -1;
}

/*
 int main(){
 BinaryTreeNode* root = new BinaryTreeNode(1);
 BinaryTreeNode* node2 = new BinaryTreeNode(2);
 BinaryTreeNode* node3 = new BinaryTreeNode(3);
 BinaryTreeNode* node4 = new BinaryTreeNode(4);
 BinaryTreeNode* node5 = new BinaryTreeNode(5);
 BinaryTreeNode* node6 = new BinaryTreeNode(6);
 root->left = node2;
 root->right = node3;
 node2->left = node4;
 node3->right = node6;
 node4->right = node5;
 
 if(isBalancedBT_fast(root)){
 cout << 1 << endl;
 }else{
 cout << 0 << endl;
 }
 
 return 0;
 }*/
