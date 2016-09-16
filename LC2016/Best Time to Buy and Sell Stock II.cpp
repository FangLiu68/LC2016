//
//  Best Time to Buy and Sell Stock II.cpp
//  LC2016
//
//  Created by Fang Liu on 7/25/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like, (eg. buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 并没有限制买卖次数，只限制了当天只能买或者卖。
 所以可以采用greedy的方法，来获得所有可能的正利润。
 2 1 3 4 5 4 2 8 7
 (3-1)+(4-3)+(5-4)+(8-2) = (5-1)+(8-2)
 只要prices[i]>prices[i-1]>0, 我们就在第i-1天买入，第i天抛出。这样可以报考所有可能赚取利润的区间。
 */

int maxProfitII(vector<int>& prices) {
    if(prices.empty()) return 0;
    
    int res = 0;
    for(int i=1; i<prices.size(); ++i){
        if(prices[i] - prices[i-1] > 0){
            res = res + (prices[i] - prices[i-1]);
        }
    }
    
    return res;
}