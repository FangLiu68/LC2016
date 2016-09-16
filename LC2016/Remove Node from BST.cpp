//
//  Remove Node from BST.cpp
//  LC2016
//
//  Created by Fang Liu on 4/8/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Remove a target node from BST
 */

#include "BinaryTree.h"
#include <iostream>
using namespace std;

/*
 step 1. find the target node first. While traversing the tree to find the target node, we want to keep trackof the parent/previous node when we go down to the next level.
 step 2. 
    case1: if the target node has no child, this case is easy. parent->left = null
    case2: 
 */