//
//  Quick Sort Array.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 quick sort
 principle: iterate over the whole array, and put all numbers smaller than pivot to the left, then put the pivot following (all numbers larger than the pivot are already on the pivot's right hand)
 implementation details: first put the pivot to the right most position (swap(arr[pivot], arr[right])).
 */

/*
 1 9 8 5 3
 
 1st Question:
 what  is the final position of 5?  5 is randomly selected (5 is called pivot).
 
 principle:
 iterate over the whole array, and put all numbers smaller than 5 to the left, then put 5 following (all numbers larger than 5 are already on 5’s r-hand).
 
 implementation details:
 first put 5 to the right most position (swap(5, 3)).
 
 两个挡板 i j ,三个区域 a) b) c) 的思想：
 a) [0...i) :   i 的左侧（不包含i） 全部为比pivot小的数
 b) [i...j]:    i 和 j 之间为未知探索区域
 c) (j...n-1]:  j 的右侧(不包含j) 全部为比pivot大或等于的数字
 
 1 9 8 3 5    current number: 1 .  1 < 5, so nothing changes, we will look at the next number 9
 i     j
 1 9 8 3 5    current number: 9.  9 > 5, so put 9 to the number to the left of 5, ⇒  swap(9, 3)
 i   j
 1 3 8 9 5    current number: 3.  3 < 5, so nothing changes, we look at the next number 8
 i j
 1 3 8 9 5    current number: 8.  8 > 5, so put 8 to the number to the left of 9
 ij         (9 was the left boundary of all numbers that are larger than 5)
 
 1 3 5 9 8   finally, 5 is put to the right and FINAL position   (by calling swap(5, 8))
 Recursive rule:
 Quicksort all numbers to the left of 5,
 Quicksort all numbers to the right of 5,
 */

int partition(int arr[], int left, int right);

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot_position = partition(arr, left, right);
        
        quickSort(arr, left, pivot_position-1);
        quickSort(arr, pivot_position+1, right);
    }
}

void quickSort(int arr[], int len){
    if(arr == NULL || len <= 0){
        return;
    }
    quickSort(arr, 0, len-1);
}

// partition返回的是一个Index，这个index所指向的数字在他正确的位置上
int partition(int arr[], int left, int right){
    int index_pivot = left + (right - left)/2;
    int pivot = arr[index_pivot];
    
    swap(arr[index_pivot], arr[right]);
    
    int left_bound = left;
    int right_bound = right - 1;
    
    // 保证leftBound的左边都是<pivot的值，rightBound的右边都是>=pivot的值，直到两者都不符合条件时，互换两者指向的元素，同时leftBound和rightBound都各自往前走
    while(left_bound <= right_bound){
        if(arr[left_bound] < pivot){
            left_bound++;
        }else if(arr[right_bound] >= pivot){
            right_bound--;
        }else{
            swap(arr[left_bound++], arr[right_bound--]);
        }
    }
    
    // 此时，leftBound指向的位置的左边所有的数都小于pivot，leftBound位置的右边的所有的数都大于等于pivot
    // 所以我们需要swap back pivot(在arr[right]的位置上)，把他放回他在arr中正确的位置上
    swap(arr[left_bound], arr[right]);
    return left_bound;
}




