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
 10  root (2 times getHeight n/2 + n/2)-->O(n)
 /                  \
 5(2 times getHeight  n/2)       15(n/2)  -->O(n)
 /               \               /   \
 3(N/4)             9(N/4)     12(N/4)  20(N/4)
 total level = log(n) level
 for each level   O(n)
 So, the total time complexity = O(nlog(n))
 对每一个node T来说，getHeight(T)的复杂度是以T为根节点的所有子节点的个数
 例如：
 对根节点10来说，getHeight(10)=getHeight(5)+getHeight(15)
 假设整个树一共有N个node，假设说是完全二叉树，那么10的左子树一共有N/2个node, 右子树有N/2个Node，
 那么第一行对getHeight(10)的BIGO是N/2+N/2 = N
 第二行对节点5来说，getHeight(5) = getHeight(3)+getHeight(9)
 同样，由于3和9都各自拥有N/4个node的subtree，所以getHeight(3)和getHeight(9)各自的复杂度都是N/4，所以getHeight(5)的复杂度是N/2
 所以5的兄弟getHeight(15)的复杂度也是N/2
 那么第二行一共的getHeight的复杂度为：getHeight(5)+getHeight(15) = N/2 + N/2 = N
 ....
 每一行的所有getHeight的复杂度一共是N
 整个树一共有logN行
 所以isBlanced(root)这种算法的复杂度一共是NlogN
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

// each node, we have to find its height O(N), totally logN level, so time O(NlogN)
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
