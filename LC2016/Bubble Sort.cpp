//
//  Bubble Sort.cpp
//  LC2016
//
//  Created by Fang Liu on 8/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Bubble Sort
 This algorithm works by comparing each item in the list with the item next to it, and swapping them if required. In other words, the largest element has bubbled to the top of the array. The algorithm repeats this process until it makes a pass all the way through the list without swapping any items.
 */

#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& input){
    if(input.empty()){
        return;
    }
    
    for(int i=0; i<input.size()-1; ++i){
        for(int j=i+1; j<input.size(); ++j){
            if(input[i] > input[j]){
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
}

/*
int main(){
    vector<int> input = {3, 6, 1, 4, 2, 5};
    bubbleSort(input);
    for(int i=0; i<input.size(); ++i){
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}*/