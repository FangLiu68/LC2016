//
//  Decompress Str I.cpp
//  LC2016
//
//  Created by Fang Liu on 4/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a string in compressed form, decompress it to the original string. The adjacent repeated characters in the original string are compressed to have the character followed by the number of repeated occurrences. If the character does not have any adjacent repeated occurrences, it is not compressed.
 
 Assumptions
 The string is not null
 The characters used in the original string are guaranteed to be ‘a’ - ‘z’
 There are no adjacent repeated characters with length > 9
 
 Examples
 “acb2c4” → “acbbcccc”
 */

#include <string>
#include <iostream>
using namespace std;

string decompress_strI(string input){
    if(input.empty()) return input;
    
    string res;
    
    for(int i=0; i<input.size(); ++i){
        if(i+1<input.size() && input[i+1]>='0' && input[i+1]<='9'){
            int count = input[i+1] - '0';
            for(int j=0; j<count; ++j){
                res.push_back(input[i]);
            }
            i++;
        }else{
            res.push_back(input[i]);
        }
    }
    
    return res;
}

/*
int main(){
    string input = "a3";
    cout << decompress_strI(input) << endl;
    return 0;
}*/