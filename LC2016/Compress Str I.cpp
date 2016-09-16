//
//  Compress Str I.cpp
//  LC2016
//
//  Created by Fang Liu on 4/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string.
 */

#include <string>
#include <iostream>
using namespace std;

string compress_strI(string input){
    if(input.empty()){
        return input;
    }
    
    // count length of the final string
    int final_len = 0;
    char pre = input[0];
    for(int i=1; i<input.size(); ++i){
        if(pre == input[i]){
            continue;
        }else{
            final_len = final_len + 2;
            pre = input[i];
        }
    }
    
    final_len = final_len + 2;
    
    if(final_len >= input.size()){
        return input;
    }else{
        string res;
        int len = 1;
        char pre = input[0];
        for(int i=1; i<input.size(); ++i){
            if(pre == input[i]){
                len++;
            }else{
                res.push_back(pre);
                res.push_back(len + '0');
                pre = input[i];
                len = 1;
            }
        }
        // aabb
        res.push_back(pre);
        res.push_back(len + '0');
        
        return res;
    }
}

/*
int main(){
    string input1 = "aab";
    string input2 = " ";
    string input3 = "aaaabcccccccdeeaaa";
    cout << compress_strI(input3) << endl;
    return 0;
}*/