//
//  Remove Dup in Unsorted Arr repeatedly.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Given an unsorted array, deduplication for adjacent letters repeatedly

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

/*
 corner case: do not forget to reverse the string from the stack
 */
vector<int> remove_dup_repeatedly(vector<int> input){
    vector<int> res;
    if(input.size() <= 1){
        return input;
    }
    
    stack<int> stk;
    stk.push(input[0]);
    
    for(int i = 1; i < input.size();){
        int cur = input[i];
        if(stk.size() > 0 && cur == stk.top()){
            while(i < input.size() && cur == input[i]){
                i++;
            }
            stk.pop();
        }else{
            stk.push(input[i++]);
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
    vector<int> input = {4, 4, 2, 2, 4, 3, 5, 5, 3, 6, 9};
    vector<int> res = remove_dup_repeatedly(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}*/