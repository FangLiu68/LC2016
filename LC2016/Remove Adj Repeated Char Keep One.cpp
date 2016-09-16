//
//  Remove Adj Repeated Char.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Remove adjacent, repeated characters in a given string, leaving only one character for each group of such characters.
 
 Assumptions
 Try to do it in place.
 Examples
 “aaaabbbc” is transferred to “abc”
 Corner Cases
 If the given string is null, we do not need to do anything.
 
 there shouldn't have space right???
 */

#include <string>
#include <iostream>
using namespace std;

/* slow, fast pointer starts from index 1
   left of slow (not including) slow are the result we want
   O(N) runtime, O(1) space
*/
string removeAdjRepeatedChar(string input){
    if(input.size() <= 1){
        return input;
    }
    
    int slow = 1;
    int fast = 1;
    
    while(fast < input.size()){
        if(input[slow-1] == input[fast]){
            fast++;
        }else{
            input[slow++] = input[fast];
        }
    }
    
    return input.substr(0, slow);
}

string removeAdjRepeatedChar2(string input){
    if(input.empty()){
        return " ";
    }
    int slow = 0;
    int fast = 0;
    while(fast < input.size()){
        if(input[slow] == input[fast]){
            fast++;
        }else{
            input[++slow] = input[fast];
        }
    }
    return input.substr(0, slow+1);
}

/*
int main(){
    string input = "aaaabbbbc  ccc";
    cout << removeAdjRepeatedCharII(input) << endl;
    return 0;
}*/