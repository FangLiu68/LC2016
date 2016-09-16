//
//  Maximum Product Subarray.cpp
//  LC2016
//
//  Created by Fang Liu on 7/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 For example, given the array [2, 3, -2, 4]
 the contiguous subarray [2, 3] has the largest product = 6
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 MIN[i] = the min subarray of product ending at index i
 MAX[i] = the max subarray of product ending at index i
 
 base case: MIN[0] = MAX[0] = input[0]
 MIN[i] = min(input[i], MIN[i-1]*input[i], MAX[i-1]*input[i])
 MAX[i] = max(input[i], MIN[i-1]*input[i], MAX[i-1]*input[i])
 */

int maxProduct(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }
    
    vector<int> min_record(nums.size(), 1);
    vector<int> max_record(nums.size(), 1);
    min_record[0] = max_record[0] = nums[0];
    int res = max_record[0];
    
    for(int i=1; i<nums.size(); ++i){
        min_record[i] = min(nums[i], min(min_record[i-1]*nums[i], max_record[i-1]*nums[i]));
        max_record[i] = max(nums[i], max(min_record[i-1]*nums[i], max_record[i-1]*nums[i]));
        res = max(res, max_record[i]);
    }
    
    return res;
}
/*
int main(){
    vector<int> input = {2, 3, -2, 4};
    cout << maxProduct(input) << endl;
    return 0;
}*/