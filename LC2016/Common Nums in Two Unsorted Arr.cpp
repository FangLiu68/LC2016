//
//  Common Nums in Two Unsorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/*
 Find all numbers that appear in both of the two unsorted arrays.
 
 Assumption
 Both arrays are not null.
 There are no duplicate numbers in each of the two arrays respectively.
 Exmaples
 A = {1, 2, 3}, B = {3, 1, 4}, return [1, 3]
 A = {}, B = {3, 1, 4}, return []
 */

// use set to contain one array's elements, then search each elem from another array
// O(N) runtime, O(N) space
vector<int> common_num_TwoSortedArr_noDup(vector<int> input1, vector<int> input2){
    vector<int> res;
    if(input1.empty() || input2.empty()) return res;
    unordered_set<int> st;
    for(int i=0; i<input1.size(); ++i){
        st.insert(input1[i]);
    }
    for(int i=0; i<input2.size(); ++i){
        if(st.find(input2[i]) != st.end()){
            res.push_back(input2[i]);
        }
    }
    return res;
}



/*
 Find all numbers that appear in both of two unsorted arrays.
 
 Assumptions
 Both of the two arrays are not null.
 In any of the two arrays, there could be duplicate numbers.
 Examples
 A = {1, 2, 3, 2}, B = {3, 4, 2, 2, 2}, return [2, 2, 3] (there are both two 2s in A and B)
 */
// 有重复元素，就不能用set，要先排序，再比较
// O(NlogN) runtime
vector<int> common_num_TwoSortedArr_hasDup(vector<int> input1, vector<int> input2){
    vector<int> res;
    if(input1.empty() || input2.empty()) return res;
    sort(input1.begin(), input1.end());
    sort(input2.begin(), input2.end());
    int index1 = 0;
    int index2 = 0;
    while(index1 < input1.size() && index2 < input2.size()){
        if(input1[index1] == input2[index2]){
            res.push_back(input1[index1]);
            index1++, index2++;
        }else if(input1[index1] < input2[index2]){
            index1++;
        }else{
            index2++;
        }
    }
    return res;
}