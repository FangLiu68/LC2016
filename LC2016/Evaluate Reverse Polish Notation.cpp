//
//  Evaluate Reverse Polish Notation.cpp
//  LC2016
//
//  Created by Fang Liu on 3/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 Some examples:
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
 use stack
 遇到是数字，就push into the stack
 遇到是符号，就pop two top elements from the stack, 做运算，then push the result back into stack
 then go on. until there is only one element left in the stack, which is the result.
 */

bool isSymbol(string str){
    if(str.empty()){
        return false;
    }
    if(str == "+" || str == "-" || str == "*" || str == "/"){
        return true;
    }else{
        return false;
    }
}

int reverse_polish_notation(vector<string>& tokens){
    if(tokens.empty()){
        return INT_MIN;
    }
    
    stack<int> temp_res;
    
    for(int i=0; i<tokens.size(); ++i){
        if(isSymbol(tokens[i])){
            int num2 = temp_res.top();
            temp_res.pop();
            int num1 = temp_res.top();
            temp_res.pop();
            if(tokens[i] == "+"){
                temp_res.push(num1 + num2);
            }else if(tokens[i] == "-"){
                temp_res.push(num1 - num2);
            }else if(tokens[i] == "*"){
                temp_res.push(num1 * num2);
            }else if(tokens[i] == "/"){
                temp_res.push(num1 / num2);
            }
        }else{
            temp_res.push(stoi(tokens[i]));
        }
    }
    
    return temp_res.top();
}

/*
int main(){
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    int res = reverse_polish_notation(tokens);
    cout << res << endl;
    return 0;
}
*/