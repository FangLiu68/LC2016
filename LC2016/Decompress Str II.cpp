//
//  Decompress Str II.cpp
//  LC2016
//
//  Created by Fang Liu on 4/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a string in compressed form, decompress it to the original string. The adjacent repeated characters in the original string are compressed to have the character followed by the number of repeated occurrences.
 
 Assumptions
 The string is not null
 The characters used in the original string are guaranteed to be ‘a’ - ‘z’
 There are no adjacent repeated characters with length > 9
 
 Examples
 “a1c0b2c4” → “abbcccc”
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

string decompress_strII(string input){
    if(input.empty()){
        return input;
    }
    string res;
    
    for(int i=0; i<input.size(); ++i){
        int cur_count = input[i+1] - '0';
        for(int j=0; j<cur_count; ++j){
            res.push_back(input[i]);
        }
        i++;
    }
    
    return res;
}

string decompress_strII_inplace(string input){
    if(input.empty()){
        return input;
    }
    
    vector<pair<char, int>> v;
    int final_size = 0;
    
    for(int i=0; i<input.size()-1; i=i+2){ // 注意这里每次i+2
        v.push_back(make_pair(input[i], input[i+1]-'0'));
        final_size = final_size + input[i+1]-'0';
    }
    
    if(final_size == 0){ // a0b0c0d0  则直接返回空
        return " ";
    }
    
    input.resize(final_size); // 不能忘了
    
    int cur_index = 0;
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[i].second; ++j){
            input[cur_index++] = v[i].first;
        }
    }
    
    return input;
}

/*
int main(){
    string input = "a1c0b2c4a3";
    cout << decompress_strII_inplace(input) << endl;
    return 0;
}*/