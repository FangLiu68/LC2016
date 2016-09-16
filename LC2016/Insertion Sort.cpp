//
//  Insertion Sort.cpp
//  LC2016
//
//  Created by Fang Liu on 8/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Insertion Sort
 to sort unordered list of elements, we remove its engries one at a time and then insert each of them into a sorted part (initially empty)
 */

#include <vector>
#include <iostream>
using namespace std;

void insertion_sort(vector<int>& input){
    if(input.empty()){
        return;
    }
    
    for(int i=1; i<input.size(); i++){
        int cur = input[i];
        int j = i;
        while(j>0 && input[j-1]>cur){
            input[j] = input[j-1];
            j--;
        }
        input[j] = cur;
    }
}

/*
int main(){
    vector<int> input = {4, 2, 1, 5, 3, 8};
    insertion_sort(input);
    for(int i=0; i<input.size(); ++i){
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}*/