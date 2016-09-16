//
//  String Matching.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 A word such as “book” can be abbreviated to 4, 1o1k, b3, b2k, etc. Given a string and an abbreviation, return if the string matches the abbreviation.  Assume the original string only contains alphabetic characters. For example:  “s11d” matches “sophisticated”.
 */

#include <string>
#include <iostream>
using namespace std;

bool isDigit(char input){
    return input >= '0' && input <= '9';
}

bool str_matching(string s1, string s2){
    // base case
    if(s1.size() == 0 && s2.size() == 0){
        return true;
    }else if(s1.size() == 0 || s2.size() == 0){
        return false;
    }
    
    if(!isDigit(s2[0])){
        if(s1[0] != s2[0]){
            return false;
        }else{
            return str_matching(s1.substr(1), s2.substr(1));
        }
    }else{
        int i = 0;
        int num = 0;
        while(i < s2.size() && isDigit(s2[i])){
            num = num*10 + s2[i] - '0';
            ++i;
        }
        if(num > s1.size()){
            return false;
        }else{
            return str_matching(s1.substr(num), s2.substr(i));
        }
    }
}

/*
int main(){
    string s1 = "book";
    string s2 = "b5";
    if(str_matching(s1, s2)){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}*/