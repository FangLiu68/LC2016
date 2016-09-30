//
//  Find Num of Subsequences Sum to K.cpp
//  LC2016
//
//  Created by Fang Liu on 9/24/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an integer array of size n and a number K (0 < K <= n), return number of consecutive subsequences whose sum equals K.
 
 Example:
    [5, 4, 9,   2,  2,  7,  1,  1, 12, -2,  3] and 13
 [0, 5, 9, 18, 20, 22, 29, 30, 31, 43, 41, 44]
 return 5
 [4, 9]
 [9, 2, 2]
 [2, 2, 7, 1, 1]
 [1, 12]
 [12, -2, 3]
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int numOfWays(vector<int> input, int target){
    if(input.empty()) return 0;

    map<int, int> count;
    count[0] = 1;
    int res = 0;
    int preSum = 0;

    for(int i=0; i<input.size(); ++i){
        preSum += input[i];
        int counterpartSum = preSum - target;

        int counterpartCount = count[counterpartSum];
        if(counterpartCount != 0){
            res += counterpartCount;
        }

        int cnt = count[preSum];
        if(cnt == 0){
            count[preSum] = 1;
        }else{
            count[preSum] = cnt + 1;
        }
    }

    return res;
}

/*
int main(){
    vector<int> input = {5,4,9,2,2,7,1,1,12,-2,3};
    int target = 13;
    cout << numOfWays(input, target) << endl;
    return 0;
}*/
