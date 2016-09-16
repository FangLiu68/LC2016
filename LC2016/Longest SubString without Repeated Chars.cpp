//
//  Longest SubString without Repeated Chars.cpp
//  LC2016
//
//  Created by Fang Liu on 4/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a string, find the length of the longest substring without repeating characters.
 eg, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3
 for "bbbb" the longest substring is "b", with the lenght of 1.
 */

#include <string>
#include <set>
#include <iostream>
using namespace std;

/*
 slow, fast all start from index 0
 [slow, fast) contain all the distinct chars
 use a container to hold all unrepeated chars
 and use one counter to keep track the max length between (fast-slow)
 
 when fast find un-repeated char, we push to set, and fast++
 when fast find repeated char, we pop input[slow] out of the container, at the meantime slow++, we keep doing this until slow move to the repeated char(which fast is pointing to)'s next char
 */
int longest_substr_no_repeated_charI(string input){
    if(input.size() <= 1){
        return input.size();
    }
    
    int slow = 0;
    int fast = 0;
    set<char> no_dup;
    int res = 0;
    
    while(fast < input.size()){
        if(no_dup.find(input[fast]) == no_dup.end()){ // input[fast] is not in the set
            no_dup.insert(input[fast++]);
            res = max(res, fast-slow); // 此时right已经+1，所以长度正好是所需要结果
        }else{
            no_dup.erase(input[slow++]);
        }
    }
    return res;
}



string longest_substr_no_repeated_char(string input){
    if(input.size() <= 1){
        return input;
    }
    string res;
    set<char> s;
    int left = 0;
    int right = 0;
    while(right < input.size()){
        if(s.find(input[right]) != s.end()){
            s.erase(input[left++]);
        }else{
            s.insert(input[right++]);
            if(right - left > res.size()){
                res = input.substr(left, right - left);
            }
        }
    }
    return res;
}
/*
int main(){
    string input = "BDEFGADHPDEF";
    cout << longest_substr_no_repeated_charI(input) << endl;
    return 0;
}
*/