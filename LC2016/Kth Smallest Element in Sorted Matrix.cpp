//
//  Kth Smallest Element in Sorted Matrix.cpp
//  LC2016
//
//  Created by Fang Liu on 8/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a n*n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
 Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 
 Example:
 matrix = [
 [ 1,  5,  9],
 [10, 11, 13],
 [12, 13, 15]
 ],
 k = 8,
 return 13.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ n2.
 */

#include <queue>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

// <value, <x-index, y-index>>
struct Comp{
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
        return p1.first > p2.first; // min heap
    }
};

int kth_smallest_in_sortedMatrix(vector<vector<int>>& matrix, int k){
    if(matrix.empty() || matrix[0].empty()){
        return INT_MAX;
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Comp> min_heap; // <value, <index_x, index_y>>
    set<pair<int, int>> st; // <index_x, index_y>
    
    int row = 0;
    int col = 0;
    min_heap.push(make_pair(matrix[row][col], make_pair(row, col)));
    st.insert(make_pair(row, col));
    
    int res = INT_MIN;
    
    for(int i=0; i<k; ++i){
        pair<int, pair<int, int>> cur = min_heap.top();
        min_heap.pop();
        
        res = cur.first;
        row = cur.second.first;
        col = cur.second.second;
        
        if(row+1<matrix.size() && st.find(make_pair(row+1, col))!=st.end()){
            min_heap.push(make_pair(matrix[row+1][col], make_pair(row+1, col)));
            st.insert(make_pair(row+1, col));
        }
        
        if(col+1<matrix[row].size() && st.find(make_pair(row, col+1))!=st.end()){
            min_heap.push(make_pair(matrix[row][col+1], make_pair(row, col+1)));
            st.insert(make_pair(row, col+1));
        }
    }
    
    return res;
}