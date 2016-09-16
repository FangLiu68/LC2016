//
//  K Smallest Elem in Unsorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 3/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the K smallest numbers in an unsorted integer array A. The returned numbers should be in ascending order.
 Assumptions
 A is not null
 K is >= 0 and smaller than or equal to size of A
 Return an array with size K containing the K smallest numbers in ascending order
 Examples
 A = {3, 4, 1, 2, 5}, K = 3, the 3 smallest numbers are {1, 2, 3}
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
 1. sort array and then return the left K elements. O(NlogN)
 2. heapify the array to make a new MIN_HEAP    O(N)
 pop out k times, then done.                 O(KlogN)
 total O(N+KlogK)
 space O(N)
 3. build a MAX_HEAP of size k with the first k elements.   O(K)
 interate over from k+1 elements all the way to the nth elements, and for each ith element, if ith element is smaller than the top element, then remove top and insert ith element.    2(n-k)logk
 total O(K+2(N-K)logK)=> O(NlogK)
 space O(K)
 所以当K较小的时候，取最大K个值就用min_heap，取最小K个值就用max_heap
 */

// use a max heap of size k. we always maintain a heap of size k so that the smallest k elements are always there.

vector<int> k_smallest_from_unsorted_arr(vector<int> input, int k){
    vector<int> res;
    if(input.empty()){
        return res;
    }
    priority_queue<int> maxHeap;
    for(int i = 0; i < input.size(); ++i){
        if(i < k){
            maxHeap.push(input[i]);
        }else if(input[i] < maxHeap.top()){
            maxHeap.pop(); // O((n-k)logk)
            maxHeap.push(input[i]); // O((n-k)logk)
        }
    }
    while(!maxHeap.empty()){
        res.push_back(maxHeap.top());
        maxHeap.pop(); // klogk
    }
    sort(res.begin(), res.end());
    return res;
}