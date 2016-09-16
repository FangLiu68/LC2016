//
//  Common Elem in 3 Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// find the common elements in three sorted arrays

#include <iostream>
using namespace std;

// each time we remove the smallest one
void common_elem_in_3SortedArr(int arr1[], int len1, int arr2[], int len2, int arr3[], int len3){
    if(arr1 == NULL || arr2 == NULL || arr3 == NULL || len1 <=0 || len2 <= 0 || len3 <= 0){
        return;
    }
    
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    while(index1 < len1 && index2 < len2 && index3 < len3){
        if(arr1[index1] == arr2[index2] && arr2[index2] == arr3[index3]){
            cout << arr1[index1] << " ";
            index1++, index2++, index3++;
        }else if(arr1[index1] < arr2[index2] && arr1[index1] < arr3[index3]){
            index1++;
        }else if(arr2[index2] < arr1[index1] && arr2[index2] < arr3[index3]){
            index2++;
        }else{
            index3++;
        }
    }
    
    cout << endl;
}

/*
int main(){
    int arr1[] = {1, 2, 4, 5, 6, 10};
    int arr2[] = {2, 5, 7, 10, 12};
    int arr3[] = {1, 2, 3, 5, 10, 12};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    int len3 = sizeof(arr3) / sizeof(int);
    
    common_elem_in_3SortedArr(arr1, len1, arr2, len2, arr3, len3);
    
    return 0;
}*/

