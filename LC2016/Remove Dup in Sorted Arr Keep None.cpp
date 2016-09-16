//
//  Remove Dup in Sorted Arr Keep None.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a sorted array, for dup elements, remove all of them.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 [0, index): processed area
 [index, i): useless
 [i, n): unknown area to explore
 */
int remove_dup_in_sortedArr_keepNone(vector<int> input){
    if(input.size() <= 1){
        return input.size();
    }
    
    bool flag = false; // indicates whether we are currently having duplication
    int index = 0; // slow index
    
    for(int i=1; i<input.size(); ++i){
        // case 1: if the element scanned == index element
        if(input[i] == input[index]){
            flag = true;
        }
        // case 2: not case 1 and we don't have dup
        else if(flag == false){
            input[++index] = input[i];
        }
        // case 3: not case 1 2, and input[i] != input[index]
        else{
            input[index] = input[i];
            flag = false;
        }
    }
    
    if(!flag) index++;
    return index;
}