//
//  Best Time to Buy and Sell Stock.cpp
//  LC2016
//
//  Created by Fang Liu on 7/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (eg, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 
 Example 1:
 Input: [7, 1, 5, 3, 6, 4]
 Output: 5
 max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 
 Example 2:
 Input: [7, 6, 4, 3, 1]
 Output: 0
 In this case, no transaction is done, i.e. max profit = 0.
 */

#include <iostream>
#include <vector>
using namespace std;

int maxProfitI(vector<int>& profit){
    if(profit.size() < 2){
        return 0;
    }
    
    int max_diff = 0;
    int cur_min = profit[0];
    
    for(int i=1; i < profit.size(); ++i){
        max_diff = max(max_diff, profit[i] - cur_min);
        cur_min = min(cur_min, profit[i]);
    }
    
    return max_diff;
}

int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;
    
    int res = 0;
    int minPrice = prices[0];
    
    for(int i=1; i<prices.size(); ++i){
        if(prices[i] > minPrice){
            res = max(prices[i] - minPrice, res);
        }else{
            minPrice = prices[i];
        }
    }
    
    return res;
}
