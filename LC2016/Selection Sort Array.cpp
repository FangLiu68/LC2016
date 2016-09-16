//
//  Selection Sort.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 The algorithm works by selecting the smallest unsorted item and then swapping it with the item in the next position to be filled.
 The selection sort works as follows:
 you look through the entire array for the smallest element, once you find it you swap it (the smallest element) with the first element of the array. then you look for the smallest element in the remaining array (an array without the first element) and swap it with the second element. then you look for the smallest element in the remaining array (an array without first and second element) and swap it with the third element, and so on. here is the
 */

/*
 Given an array of intergers, sort the elements in the array in ascending order. The selection sort algorithm should be used to solve this problem.
 Examples
 {1} is sorted to {1}
 {1, 2, 3} is sorted to {1, 2, 3}
 {3, 2, 1} is sorted to {1, 2, 3}
 {4, 2, -3, 6, 1} is sorted to {-3, 1, 2, 4, 6}
 Corner Cases
 What if the given array is null? In this case, we do not need to do anything.
 What if the given array is of length zero? In this case, we do not need to do anything
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 O(N^2) runtime, O(1) space
 
 时间复杂度分析：
 for (int i = 0; i < n-1; i++)       // outer
    for (int j = i+1; i < n-1; i++)  // inner
 iteration j = 0: inner       (0..n-1)   = 4
 iteration j = 1: inner n-1   (1..n-1)   = 3
 iteration j = 2: inner n-2   (2..n-1)   = 2
 iteration j = 3: inner n-2   (2..n-1)   = 1
 1+2+3+4+..+n = n(n-1)/2 -> n^2 → O(n^2) time complexity
 */

void selectionSort(int arr[], int len){
    if(arr == NULL || len <=0){
        return ;
    }
    
    int global = INT_MAX;
    
    // outer loop: how many iterations
    for(int i=0; i < len-1; ++i){
        global = i;
        
        // inner loop: find the global min from the rest elements
        for(int j = i+1; j < len; ++j){
            if(arr[global] > arr[j]){
                global = j; // record the index of the smallest element
            }
        }
        
        // swap teh global(arr[index]) min with arr[i]
        int temp = arr[i];
        arr[i] = arr[global];
        arr[global] = temp;
    }
}

void selectionSort_vector(vector<int>& arr){
    if(arr.size() <= 1){
        return;
    }
    int global;
    for(int i = 0; i < arr.size()-1; ++i){
        global = i;
        for(int j = i+1; j < arr.size(); ++j){
            if(arr[global] > arr[j]){
                global = j;
            }
        }
        // swap global min to arr[i]
        int temp = arr[i];
        arr[i] = arr[global];
        arr[global] = temp;
    }
}


/*
 int main(){
 vector<int> arr = {4, 2, 1, 6, 5};
 selectionSort_vector(arr);
 for(int i=0; i<arr.size(); ++i){
 cout << arr[i] << " ";
 }
 cout << endl;
 return 0;
 }*/