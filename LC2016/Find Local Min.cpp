//
//  Find Local Min.cpp
//  LC2016
//
//  Created by Fang Liu on 12/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an unsorted integer array, return the position of any local minimum.
 +infi {1,3,5,6,5}+infi
 local min: less than its left and right number
 you can assume the head and tail of this array are positive infinite
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 Binary Search and post processing
 if arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1], return mid
 if arr[mid]>arr[mid+1], left = mid;
 else, right = mid
 
 complexity:
 time O(logN), space O(1)
 
 test case:
 arr[1,3,5,6,5], return 0
 arr[0], return 0
 arr[2,2], return 1
 */
int find_local_min(vector<int> arr){
    if(arr.empty()){
        return -1;
    }
    int left = 0;
    int right = arr.size() - 1;

    while(left+1 < right){
        int mid = left + (right-left)/2;
        if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
            return mid;
        }else if(arr[mid] > arr[mid+1]){
            left = mid;
        }else{
            right = mid;
        }
    }

    return arr[left]<arr[right]? left:right;
}
/*
int main(){
    vector<int> arr = {2,2};
    cout << find_local_min(arr) << endl;
    return 0;
}
*/
