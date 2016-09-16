//
//  Compress Str II.cpp
//  LC2016
//
//  Created by Fang Liu on 4/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a string, replace adjacent repeated characters with the character followed by the number of repeated occurrences. If the character does not has any adjacent repeated occurrences, it is not changed.
 
 Assumptions:
 The string is not null
 The characters used in the original string are guaranteed to be 'a' - 'z'
 There are no adjacent repeated characters with length > 9
 
 Exmamples
 “abbcccdeee” → “ab2c3de3”
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string compress_strII(string input){
    if(input.empty()){
        return input;
    }
    
    string res;
    int pre_len = 1;
    char pre = input[0];
    
    for(int i=1; i<input.size(); ++i){
        if(pre == input[i]){
            pre_len++;
        }else{
            if(pre_len == 1){
                res.push_back(pre);
            }else{
                res.push_back(pre);
                res.push_back(pre_len + '0');
            }
            pre_len = 1;
            pre = input[i];
        }
    }
    
    if(pre_len == 1){
        res.push_back(pre);
    }else{
        res.push_back(pre);
        res.push_back(pre_len + '0');
    }
    
    return res;
}

// do it inplace
void compress_strII_inplace(string& input){
    if(input.empty()){
        return ;
    }
    
    vector<pair<char, int>> v;
    
    char pre = input[0];
    int pre_len = 1;
    for(int i=1; i<input.size(); ++i){
        while(i<input.size() && input[i]==pre){
            pre_len++;
            i++;
        }
        pair<char, int> pre_pair = make_pair(pre, pre_len);
        v.push_back(pre_pair);
        pre = input[i];
        pre_len = 1;
    }
    
    if(pre_len == 1){
        v.push_back(make_pair(pre, 1));
    }
    
    int final_len = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i].second == 1){
            final_len = final_len + 1;
        }else{
            final_len = final_len + 2;
        }
    }
    input.resize(final_len);
    
    int cur_index = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i].second == 1){
            input[cur_index++] = v[i].first;
        }else{
            input[cur_index++] = v[i].first;
            input[cur_index++] = v[i].second + '0';
        }
    }
}

/*
int main(){
    string input1 = "abbcccdeee";
    string input2 = "aaaa";
    string input3 = "a";
    string input4 = "abbbccdd";
    string input5 = "abbbccd";
    compress_strII_inplace(input1);
    compress_strII_inplace(input2);
    compress_strII_inplace(input3);
    compress_strII_inplace(input4);
    compress_strII_inplace(input5);
    cout << input1 << endl;
    cout << input2 << endl;
    cout << input3 << endl;
    cout << input4 << endl;
    cout << input5 << endl;
    
    return 0;
}*/