//
//  Merge Sort Array.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


/*
 Given an array of intergers, sort the elements in the array in ascending order. The merge sort algorithm should be used to solve this problem.
 
 a[n] = 1,3,5,7,9,8,6,4,2,0
 1,3,5,7,9, 8,6,4,2,0                              a[10] -> a[0]...a[4]  MERGE a[5]...a[9]
                         /                     \
	     n/2          13579                     86420                        O(1) <O(n)
                   /       \                  /      \
         n/4    135        79               864      20                      O(2)<O(n)
                /   \                     /   \
         n/8   13     5        79        86   4     2 0       O( 4)
	         /  \
            1    3    5        79            86   4     20    this level time complexity == O(n)
 ====================================================================
                 13   5        79             86   4     20    this level time complexity == O(n)
                     \  /                           \  /
                     135     79                   468     02   this level time complexity == O(n)
                           \    /                           \    /
                            13579                     02468    this level time complexity == O(n)
                                     \                   /
                                       0123456789
 
 */

#include <iostream>
using namespace std;


/*
 0 1 2 3 4
 3 1 4 0 2
 mergesort 1: low 3, high 2, mid 4
 then recursively shrink the size:
 low 3, high 4, mid 1
 low 3, high 1, mid 3
 low 3, high 3
 then we touch to the bottom, arr[0]=3 is the first elem we set down, want to compare
 mergesort 2: go back to low 3, high 1, mid 3
 low 1, high 1
 then we touch to another bottom arr[1] = 1, which is the second elem we want to compare
 
 NOTE: 这里的low mid high都是index，中间遇到判断条件时都是用<=
 
 效率分析：
 1. time complexity:
 average: O(nlogn); worst case: O(nlogn)
 2. space complexity:
 worset case: O(n)
 3. stable
 */

void merge(int arr[], int helper[], int low, int mid, int high){
    if(arr == NULL || helper == NULL){
        return;
    }
    
    int index_left = low;
    int index_right = mid + 1;
    int index = low;
    
    // copy all elements from arr[] to helper[]
    for(int i = low; i <= high; ++i){
        helper[i] = arr[i];
    }
    
    while(index_left <= mid && index_right <= high){
        if(helper[index_left] <= helper[index_right]){
            arr[index++] = helper[index_left++];
        }else{
            arr[index++] = helper[index_right++];
        }
    }
    
    // if the right part of arr[] is not finished yet, we do nothing
    // if the left part of arr[] is not finished yet, we should copy those from helper[] to arr[]
    int remain = mid - index_left;
    for(int i = 0; i <= remain; ++i){
        arr[index+i] = helper[index_left + i];
    }
}

void mergeSort(int arr[], int helper[], int low, int high){
    if(low < high){
        int mid = low + (high - low)/2;
        mergeSort(arr, helper, low, mid);
        mergeSort(arr, helper, mid+1, high);
        merge(arr, helper, low, mid, high);
    }
}

void mergeSort(int arr[], int len){
    if(arr == NULL || len <= 0){
        return;
    }
    int* helper = new int[len];
    mergeSort(arr, helper, 0, len-1);
    delete[] helper;
}

/*
 int main(){
 int arr[] = {3, 1, 4, 0, 2};
 int len = sizeof(arr)/sizeof(int);
 mergeSort(arr, len);
 for(int i = 0; i < len; ++i){
 cout << arr[i] << " ";
 }
 return 0;
 }
 */