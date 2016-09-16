//
//  Deep Copy Graph.cpp
//  LC2016
//
//  Created by Fang Liu on 4/7/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


/*
 How to copy a graph with possible cycles? G -> G'
 Make a deep copy of an undirected graph, there could be cycles in the original graph.
 
 Method: build a hash_map to avoid duplication when copying a node.
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct GraphNode{
    int val;
    vector<GraphNode*> neighbors;
    GraphNode(int v) : val(v) {}
};