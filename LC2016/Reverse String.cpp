//
//  Reverse String.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// reverse a given string

#include <string>
#include <iostream>
using namespace std;

void reverseStr_iter(string input){
    if(input.empty()){
        return;
    }
    int left = 0;
    int right = input.size()-1;
    while(left <= right){
        char t = input[left];
        input[left] = input[right];
        input[right] = t;
        left++, right--;
    }
    cout << input << endl;
}

//==================================
void swap(string& input, int i, int j){
    char t = input[i];
    input[i] = input[j];
    input[j] = t;
}

void reverseStr_helper(string& input, int i, int j){
    if(input.empty() || i>=j){
        return;
    }
    swap(input, i, j);
    reverseStr_helper(input, i+1, j-1);
}

void reverseStr_recur(string& input){
    reverseStr_helper(input, 0, input.size()-1);
}
/*
int main(){
    string input = "abcd";
    reverseStr_recur(input);
    cout << input << endl;
    return 0;
}*/