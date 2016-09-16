//
//  Remove Element.cpp
//  LC2016
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesnt' matter what you leave beyond the new lenght.
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

/*
 快慢挡板
 cur的左边（不包括A[cur]）都是符合条件的结果
 runner的右边（不包括A[runner]）都是还没探索到的地方
 O(N) runtime, O(1) space
 */
int removeElement(vector<int> input, int val){
    if(input.empty()){
        return -1;
    }
    
    int cur = 0;
    int runner = 0;
    
    while(runner < input.size()){
        if(input[runner] == val){
            runner++;
        }else{
            input[cur++] = input[runner++];
        }
    }
    
    return cur;
}

// same question for a string
int removeChar(string input, char c){
    if(input.empty()){
        return -1;
    }
    
    int cur = 0;
    int runner = 0;
    
    while(runner < input.size()){
        if(input[runner] == c){
            runner++;
        }else{
            input[cur++] = input[runner++];
        }
    }
    
    return cur;
}

/*
int main(){
    vector<int> input = {2, 3, 2, 4, 7};
    int val = 2;
    cout << removeElement(input, val) << endl;
    
    string str = "abacda";
    char c = 'a';
    cout << removeChar(str, c) << endl;
    
    return 0;
}
*/