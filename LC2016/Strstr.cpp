//
//  Strstr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Determine if a small string is a substring of another larger string.
 Return the index of the first occurrence of the small string in the large string.
 Return -1 if the small string is not a substring of the large string.
 
 Assumptions
 Both large and small are not null.
 If small is empty string, return 0.
 Examples:
 "ab" is a substring of "bcabc", return 2
 "bcd" is not a substring of "bcabc", return -1
 "" is substring of "abc", return 0
 */

#include <string>
#include <iostream>
using namespace std;

// O(M*N) runtime
bool helper_match(string big, int index, string small){
    for(int i=0; i<small.size(); ++i){
        if(big[index++] != small[i]){
            return false;
        }
    }
    return true;
}

int strstr(string big, string small){
    if(small.size() > big.size()){
        return -1;
    }
    int index = 0;
    while(index <= big.size() - small.size()){
        if(helper_match(big, index, small)){
            return index;
        }else{
            index++;
        }
    }
    return -1;
}
/*
int main(){
    string big = "abcabc";
    string small = "abc";
    cout << strstr(big, small) << endl;
    return 0;
}*/