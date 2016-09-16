//
//  Array Deduplication.cpp
//  LC2016
//
//  Created by Fang Liu on 3/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an unsorted integer array, remove adjacent duplicate elements repeatedly, from left to right.
 For each group of elements with the same value do not keep any of them.
 Do this in-place, using the left side of the original array. Return the array after deduplication.
 
 Assumptions
 The given array is not null
 Examples
 {1, 2, 3, 3, 3, 2, 2} → {1, 2, 2, 2} → {1}, return {1}
 */

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/*
 stack先存当前数据，runner从当前数据的后一个开始liner scan
 如果arr[runner]==stk.top()，就一直递增runner，直到arr[runner]!=stk.top()为止，同时要stk.pop()
 如果arr[runner]!=stk.top()，就将arr[runner]放到stk里，同时递增runner
 */

vector<int> arr_dedup(vector<int> input){
    vector<int> res;
    if(input.empty()){
        return res;
    }
    
    stack<int> stk;
    stk.push(input[0]);
    int runner = 1;
    
    while(runner < input.size()){
        int cur = input[runner];
        
        if(stk.size()>0 && cur==stk.top()){
            while(runner < input.size() && cur == input[runner]){
                runner++;
            }
            stk.pop();
        }else{
            stk.push(cur);
            runner++;
        }
    }
    
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
}

/*
int main(){
    vector<int> input = {1, 2, 3, 3, 3, 2, 2};
    vector<int> res = arr_dedup(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}*/