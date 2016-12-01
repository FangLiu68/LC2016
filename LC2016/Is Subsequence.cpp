//
//  Is Subsequence.cpp
//  LC2016
//
//  Created by Fang Liu on 11/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Determine if s is t's subsequence
 
 example:
 s = "abc", t = "ahbgdc". true
 s = "axc", t = "ahbgdc". false
 */

#include <string>
#include <iostream>
using namespace std;

/*
 use two pointers
 time O(m+n)
 */
bool isValidSubsequence(string s, string t){
    if(s.empty() || t.empty() || s.size()>t.size()){
        return false;
    }

    int index_s = 0;
    int index_t = 0;

    while(index_s < s.size() && index_t < t.size()){
        if(s[index_s] == t[index_t]){
            index_s++;
        }
        index_t++;
    }

    if(index_s == s.size()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s = "axc";
    string t = "ahbgdc";
    if(isValidSubsequence(s, t)){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}
