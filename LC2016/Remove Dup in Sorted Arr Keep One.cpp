//
//  Remove Dup in Sorted Arr Keep One.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 隔板题：
 基本思想：用两个变量，一个变量记录当前指针的位置(= fast index)，一个变量记录隔板位置(= slow index)
 性质：隔板左边是处理好的元素，当前指针右边是未处理的元素，隔板和当前指针之间的区域是无用的元素。每次只要分析当前元素性质是否要加入或者移动隔板就行了。
 */

/*
 Given a sorted array, remove the dup elements and only keep one of each copy. return the new lenght of the array.
 */

#include <iostream>
#include <vector>
using namespace std;

int remove_dup_in_sortedArr_keepOne(int arr[], int len){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int cur = 0;
    for(int i=1; i<len; ++i){
        if(arr[i] != arr[cur]){
            arr[++cur] = arr[i];
        }
    }
    
    return cur+1;
}
/*
int main(){
    int arr[] = {1, 1, 2, 3, 3, 3, 3, 3, 4, 4};
    int len = sizeof(arr) / sizeof(int);
    cout << remove_dup_in_sortedArr_keepOne(arr, len) << endl;
    return 0;
}*/