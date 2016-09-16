//
//  Shift Word.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// shift the whole string to the right hand side by two bits
// eg, abcdef -> efabcd

#include <string>
#include <iostream>
using namespace std;

/*
 1. reverse the whole word. abcdef -> fedcba
 2. reverse (0, 1) and reverse (2, size-1). fe dcba → ef abcd
 */
void helper_reverse_word(string& input, int left, int right){
    while(left <= right){
        char t = input[left];
        input[left++] = input[right];
        input[right--] = t;
    }
}

void shift_word(string& input, int shift){
    if(input.empty()){
        return;
    }
    shift = shift % input.size();
    helper_reverse_word(input, 0, input.size()-1);
    helper_reverse_word(input, 0, shift-1);
    helper_reverse_word(input, shift, input.size()-1);
}
/*
int main(){
    string input = "abcdef";
    shift_word(input, 2);
    cout << input << endl;
    return 0;
}*/