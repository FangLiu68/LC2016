//
//  Valid Parentheses.cpp
//  LC2016
//
//  Created by Fang Liu on 9/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <string>
#include <stack>
#include <iostream>
using namespace std;

/*
 time O(N), space O(N)
 */
bool isValid(string s){
    if(s.empty()) return false;
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] ==  '(' || s[i] ==  '{' || s[i] ==  '[') {
            stk.push(s[i]);
        } else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
        } else if (s[i] == '}') {
            if (stk.empty() || stk.top() != '{') {
                return false;
            }
            stk.pop();
        } else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[') {
                return false;
            }
            stk.pop();
        }
    }
    return stk.size() == 0;
}
