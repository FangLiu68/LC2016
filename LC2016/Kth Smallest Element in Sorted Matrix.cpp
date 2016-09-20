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

/*
 Idea:
 start with the upper-left element. everytime we encounter an element
 we push its right and underneath neighbors to the heap(provided that they haven't been inserted before). 
 when we popped the "kth" element from the heap, we've got the kth smallest.
 
 Complexity:
 一共有k轮，每一轮都是从heap里面pop()一个，然后最多push()两个。
 heap的pop()和push()时间复杂度是多少？O(logx), x是heap的size
 因为每一轮pop一个，push两个，所以k轮之后heap最多有k个元素，所以整体上时间复杂度是 O(klogk)
 空间复杂度为O(k)
 */

#include <queue>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

// a comparator class to be used by the heap (priority_queue)
// each element of the heap is pair<value, <x-index, y-index>>
struct Comp{
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2){
        return p1.first > p2.first; // min heap
    }
};

int kth_smallest_in_sortedMatrix(vector<vector<int>>& matrix, int k){
    //if (k > N * N - 1) return -1;
    if(matrix.empty() || matrix[0].empty()){
        return INT_MAX;
    }
    
    // element in heap: <value, <index_x, index_y>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Comp> min_heap;
    // set里面可以只存x-y坐标，也可以和min_heap一样存值和坐标
    set<pair<int, int>> st; // <index_x, index_y>
    
    int row = 0;
    int col = 0;
    min_heap.push(make_pair(matrix[row][col], make_pair(row, col)));
    st.insert(make_pair(row, col));
    
    int res = INT_MIN;
    
    // 找Kth个数，循环一定要走到第K个，否则进不了循环得不到res
    for(int i=0; i<k; ++i){
        pair<int, pair<int, int>> cur = min_heap.top();
        min_heap.pop();
        
        res = cur.first;
        row = cur.second.first;
        col = cur.second.second;
        
        if(row+1<matrix.size() && st.find(make_pair(row+1, col))!=st.end()){
            // only push element to heap if it hasn't been pushed before
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
