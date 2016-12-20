//
//  Find Insert Position.cpp
//  LC2016
//
//  Created by Fang Liu on 12/20/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the inserting position in a sorted array for a target number.
 eg, [1,2,3,3,3,4,5,6], insert 3 ==> index 2
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 Find the largest smaller than the target.
 */
int find_insert_pos(vector<int> arr, int target){
    if(arr.empty()){
        return -1;
    }

    if(arr.size() == 1){
        if(arr[0] >= target){
            return 0;
        }else{
            return 1;
        }
    }

    int left = 0;
    int right = arr.size() - 1;

    while(left+1 < right){
        int mid = left + (right-left)/2;
        if(arr[mid] < target){
            left = mid;
        }else if(arr[mid] > target){
            right = mid-1;
        }else{
            right = mid-1;
        }
    }

    if(arr[right] < target){
        return right+1;
    }else if(arr[left] >= target){
        return left;
    }else{
        return right;
    }
}
/*
int main(){
    int target = 7;
    vector<int> arr1 = {1,3,5,6};
    cout << find_insert_pos(arr1, target) << endl;
    return 0;
}*/
