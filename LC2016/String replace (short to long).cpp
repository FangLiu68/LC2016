//
//  String replace (short to long).cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 In URL encoding, whenever we see an space " ", we need to replace it with "20%". Provide a method that performs this encoding for a given string.
 
 Examples
 "google/q?flo wer market" → "google/q?flo20%wer20%market"
 Corner Cases
 If the given string is null, we do not need to do anything.
 */

#include <string>
#include <iostream>
using namespace std;

string str_replace_shortToLong(string& input){
    if(input.empty()){
        return input;
    }
    
    int original_len = input.size();
    
    int num_of_blank = 0;
    for(int i=0; i<input.size(); ++i){
        if(input[i] == ' '){
            num_of_blank++;
        }
    }
    
    int final_size = original_len + 2 * num_of_blank;
    
    input.resize(final_size);
    
    int last_index = final_size-1;
    
    for(int i=original_len-1; i>=0; --i){
        if(input[i] == ' '){
            input[last_index--] = '%';
            input[last_index--] = '0';
            input[last_index--] = '2';
        }else{
            input[last_index--] = input[i];
        }
    }
    
    return input;
}
/*
int main(){
    string input = "how are you";
    cout << str_replace_shortToLong(input) << endl;
    return 0;
}*/