//
//  Find Smaller Largest Num in Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 12/24/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// find the smaller largest number in a sorted array (no dup)

#include <vector>
#include <iostream>
using namespace std;

/*
 [1,3,5,7,9]. this solution also works for having dup elements
 */
int find_smaller_largestI(vector<int>& arr, int target){
    if(arr.empty()){
        return -1;
    }

    if(arr[0] >= target){
        return -1;
    }

    int left = 0;
    int right = arr.size()-1;

    while(left+1 < right){
        int mid = left+(right-left)/2;
        if(arr[mid] == target){
            right = mid-1;
        }else if(arr[mid] < target){
            left = mid;
        }else{
            right = mid-1;
        }
    }

    return arr[right]<target? right:left;
}
/*
int main(){
    vector<int> arr = {1,2,2,3,4};
    int target = 3;
    cout << find_smaller_largestI(arr, target) << endl;
    return 0;
}*/
