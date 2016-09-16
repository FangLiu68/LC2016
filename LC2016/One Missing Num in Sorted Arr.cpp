//
//  One Missing Num in Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 [1-N], missing one number but the array is sorted
 example: {1, 3, 4, 5}, return 2
 
 M1: bucket sort. O(N) time, O(1) space
 M2: binary search, find the first index, such that a[i] = i+2, O(logN) time
 */

#include <vector>
#include <iostream>
using namespace std;

int missing_in_sortedArrI(vector<int> input){
    if(input.empty()){
        return 1;
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left < right - 1){
        int mid = left + (right-left)/2;
        if(input[mid] == mid+2){
            right = mid;
        }else if(input[mid] < mid + 2){
            left = mid;
        }
    }
    
    if(input[left] == left + 2){
        return left+1;
    }else if(input[right] == right + 2){
        return right+1;
    }
    
    return input.size()+1;
}

int missing_in_sortedArrII(vector<int> input){
    if(input.empty()){
        return 1;
    }
    for(int i=0; i<input.size(); ++i){
        if(input[i] != i+1){
            return i+1;
        }
    }

    return input.size()+1;
}

/*
int main(){
    vector<int> input = {1, 3, 4, 5};
    cout << missing_in_sortedArrII(input) << endl;
    return 0;
}*/