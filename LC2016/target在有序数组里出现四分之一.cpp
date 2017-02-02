//
//  target在有序数组里出现四分之一.cpp
//  LC2016
//
//  Created by Fang Liu on 2/1/17.
//  Copyright © 2017 Fang Liu. All rights reserved.
//

// 一个数字在排好序的数组里面出现了>1/4，求这个数

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int find_target_map(vector<int>& input){
    if(input.empty()){
        throw invalid_argument("out of boundary");
    }

    unordered_map<int, int> mp; // num, count

    for(int i=0; i<input.size(); ++i){
        if(mp.find(input[i]) == mp.end()){
            mp[input[i]] = 1;
        }else{
            mp[input[i]]++;
        }
    }

    for(unordered_map<int,int>::iterator IT = mp.begin(); IT!=mp.end(); ++IT){
        if(IT->second > input.size()/4){
            return IT->first;
        }
    }

    return INT_MIN;
}

/*
int main(){
    vector<int> input = {1,1,2,3,3,3,4,5};
    cout << find_target_map(input) << endl;
    return 0;
}*/
