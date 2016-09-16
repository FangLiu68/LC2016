//
//  Move Zero to Right End.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// move all zeros in an array to the right end of the array

#include <iostream>
using namespace std;


/*
 不在乎arr[]内部元素的顺序，则两个指针相向而行。
 
 2个挡板，3个区间
 index i左边，不包括i，都是非零
 index j右边，不包括j，都是零
 [i, j]之间，都是未探索区域
 
 任何在function内部对arr[]的改动都不影响在function外部的arr[]的原本的值
 time complexity O(N), space complexity O(1)
 */
int move_zero_to_right(int arr[], int len){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int i = 0;
    int j = len - 1;
    
    while(i <= j){
        if(arr[i] != 0){
            i++;
        }else if(arr[j] == 0){
            j--;
        }else{
            swap(arr[i++], arr[j--]);
        }
    }
    
    for(int i=0; i<len; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    return i; // then all elements on the left side of i are non-zeros (not including arr[i])
}

/*
 如果要求元素相对顺序一致，则两个指针slow, fast同向而行
 只要fast指向元素为非零，就copy arr[fast] to arr[slow]
 否则fast++
 最后记得将slow右边所有元素置零
 time complexity O(N), space complexity O(1)
 */
int move_zero_to_right_keepOrder(int arr[], int len){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int slow = 0;
    int fast = 0;
    
    while(fast < len){
        if(arr[fast] != 0){
            arr[slow++] = arr[fast++];
        }else{
            fast++;
        }
    }
    
    int res = slow;
    while(slow < len){
        arr[slow++] = 0;
    }
    
    for(int i=0; i<len; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return res;
}

/*
 int main(){
 int arr[] = {1, 2, 0, 0, 4, 0, 3, 8};
 int len = sizeof(arr) / sizeof(int);
 for(int i=0; i<len; ++i){
 cout << arr[i] << " ";
 }
 cout << endl;
 cout << move_zero_to_right_keepOrder(arr, len) << endl;
 return 0;
 }
 */