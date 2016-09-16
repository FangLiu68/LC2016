//
//  Num of Valid Parentheses.cpp
//  LC2016
//
//  Created by Fang Liu on 4/15/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// computer the number of valid expression consists of n ( and )

#include <iostream>
using namespace std;

int helper_numOfValidParentheses(int opened, int closed, int n);

int num_of_validParentheses(int n){
    if(n < 0){
        return 0;
    }
    return helper_numOfValidParentheses(0, 0, n);
}

int helper_numOfValidParentheses(int opened, int closed, int n){
    // base case
    if(opened == n && closed == n){
        return 1;
    }
    
    int res = 0;
    
    if(opened < n){
        res = res + helper_numOfValidParentheses(opened+1, closed, n);
    }
    
    if(closed < opened){
        res = res + helper_numOfValidParentheses(opened, closed+1, n);
    }
    
    return res;
}
/*
int main(){
    int n = 2;
    cout << num_of_validParentheses(n) << endl;
    return 0;
}*/