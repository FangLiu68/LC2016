//
//  Repeatly Dedup Adj Elems.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Repeatedly remove all adjacent, repeated characters in a given string from left to right.
 No adjacent characters should be identified in the final string.
 
 Examples
 "abbbaaccz" → "aaaccz" → "ccz" → "z"
 "aabccdc" → "bccdc" → "bdc"
 */

#include <stack>
#include <string>
#include <iostream>
using namespace std;

// 44224355369
string deduplicate_same_adjacent_chars(string s){
    string res;
    if(s.empty()) return res;
    
    stack<char> stk;
    stk.push(s[0]);
    
    int index_cur = 1;
    
    // cur是还没有放入stack的，即将检查的下一个char
    while(index_cur < s.size()){
        char cur = s[index_cur];
        
        // 一定要先把size check放在前面
        if(stk.size() > 0 && cur == stk.top()){
            while(index_cur < s.size() && cur == s[index_cur])
                index_cur++;
            stk.pop();
        }
        else{
            stk.push(s[index_cur++]);
        }
    }
    
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}


/*
int main(){
    string input = "44224355369";
    string input1 = "aabccdc";
    cout << deduplicate_same_adjacent_chars(input) << endl;
    return 0;
}*/