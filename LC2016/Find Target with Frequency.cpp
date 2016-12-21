//
//  4 Elements.cpp
//  LC2016
//
//  Created by Fang Liu on 12/20/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 一个数字在一个排好序的数组里面出现了>1/4，求这个数
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int find_target_with_frequency(vector<int>& arr){
    if(arr.empty()){
        return INT_MIN;
    }
    
    unordered_map<int,int> mp;
    for(int i=0; i<arr.size(); ++i){
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = 1;
        }else{
            mp[arr[i]]++;
        }
    }
    
    for(unordered_map<int,int>::iterator IT = mp.begin(); IT != mp.end(); ++IT){
        if(IT->second > arr.size()/4){
            return IT->first;
        }
    }
    
    return INT_MIN;
}
/*
int main(){
    vector<int> arr = {1,1,2,3,3,3,4,5};
    cout << find_target_with_frequency(arr) << endl;
    return 0;
}*/
