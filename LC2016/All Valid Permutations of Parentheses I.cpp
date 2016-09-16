//
//  All Valid Permutations of Parentheses I.cpp
//  LC2016
//
//  Created by Fang Liu on 4/15/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given N pairs of parentheses “()”, return a list with all the valid permutations.
 
 Assumptions
 
 N >= 0
 Examples
 
 N = 1, all valid permutations are ["()"]
 N = 3, all valid permutations are ["((()))", "(()())", "(())()", "()(())", "()()()"]
 N = 0, all valid permutations are [""]
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void helper_validParentheses(int n, int left, int right, string cur, vector<string>& res);

vector<string> validParentheses(int n){
    vector<string> res;
    string cur;
    if(n < 0){
        return res;
    }
    helper_validParentheses(n, 0, 0, cur, res);
    return res;
}

void helper_validParentheses(int n, int left, int right, string cur, vector<string>& res){
    // base case
    if(left + right == 2*n){
        res.push_back(cur);
        return;
    }
    
    // try to push '('
    if(left < n){
        cur.push_back('(');
        helper_validParentheses(n, left+1, right, cur, res);
        cur.pop_back();
    }

    // try to push ')'
    if(right < left){
        cur.push_back(')');
        helper_validParentheses(n, left, right+1, cur, res);
        cur.pop_back();
    }
}


