//
//  Remove Adj Repeated Char II.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Remove adjacent repeated characters in a given string, leaving only two characters for each group of such characters. The characters in the string are sorted in ascending order.
 
 Assumptions
 Try to do it in place.
 
 eg. "aaabbbc" -> "aabbc"
 
 corner cases: if the given string is null, we do not need to do anything.
 */

#include <string>
#include <iostream>
using namespace std;

/*
 slow, fast starts from index 2, the left of slow (not including input[slow]) are what we want
 */
string removeAdjRepeatedCharII(string input){
    if(input.size() <= 2){
        return input;
    }
    
    int slow = 2;
    int fast = 2;
    
    while(fast < input.size()){
        if(input[slow-2] == input[fast]){
            fast++;
        }else{
            input[slow++] = input[fast++];
        }
    }
    
    return input.substr(0, slow);
}
/*
int main(){
    string input = "aaaabbbbcdddee";
    cout << removeAdjRepeatedCharII(input) << endl;
    return 0;
}*/