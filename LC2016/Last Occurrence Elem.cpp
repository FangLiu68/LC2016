//
//  Last Occurrence Elem.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Given a sorted array, return the last index of the target element. If the target couldn't be found, return -1.

#include <iostream>
#include <vector>
using namespace std;

/*
 Solution:
 Binary Search.
 post-check, loop stops when index_left + 1 = index_right.
 we wanna find the last targe number, so we should check arr[right] first.
 
 Complexity:
 Time O(logN), space O(1)
 */

/*
 test case:
 arr[1,5,5,5,5], target 5, return index 4
 arr[1,1,5,5,5], target 1, return index 1
 arr[1,5], target -3, return index -1
 arr[1,5], target 8, return index -1
 arr[1,5], target 3, return index -1
 arr[1], target 1, return index 0
 arr[], target 8, return index -1
 */
int find_last_target(vector<int> arr, int target){
    if(arr.empty() || arr[0]>target || arr[arr.size()-1]<target){
        return -1;
    }
    
    int left = 0;
    int right = arr.size() - 1;
    
    while(left + 1 < right){
        int mid = left + (right - left)/2;
        if(arr[mid] == target){
            left = mid;
        }else if(arr[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    
    if(arr[right] == target){
        return right;
    }else if(arr[left] == target){
        return left;
    }else{
        return -1;
    }
}

/*
int main(){
    vector<int> arr = {1,1,5,5,5};
    int target = 1;
    cout << find_last_target(arr, target) << endl;
    return 0;
}
*/
/*
int main(){
    int arr[] = {4, 5, 5, 5, 5, 6, 6, 8};
    int len = sizeof(arr)/sizeof(int);
    int target = 5;
    cout << find_last_occur(arr, len, target) << endl;
    return 0;
}*/
