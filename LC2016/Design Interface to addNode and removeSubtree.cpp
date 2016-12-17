//
//  Design Interface to addNode and removeSubtree.cpp
//  LC2016
//
//  Created by Fang Liu on 12/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Design the storage for a class implementing this interface:
 interface Tree{
    void addNode(string key, string parent, Runnable notify);
        - check keyset
        - if not exist, create a new node, add to parent children list
    
    // return direct children of supplied key
    List<String> getChildren(string key);
 
    // remove the specified node and all its children, deeply. The notify callback for each node is called in breadth-first order
    void removeSubtree(string key);
 }
 */

#include "BinaryTree.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class StorageTree{
    
};
