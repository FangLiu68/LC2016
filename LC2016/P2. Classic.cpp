//
//  Classic.cpp
//  LC2016
//
//  Created by Fang Liu on 11/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a set of N items. each item has a weight weights[i] and a value v[i](i=1...N). the knapsack has a weight capacity W. whats the maximum total value you can get?
 
 example:
 w = 8
 weights[] = 4, 3, 5
 v[] = 3, 2, 1
 
 if we pick weights 3 and 5, then the total value is 2+1=3
 but if we pick weights 4 and 3, although the total weight is smaller, the total value is 3+2 = 5
 
 P1 is just a special case of P2, where v[i]=weights[i] for all items
 
 solution:
 M[i, w]: by using the first i items, the maximum total value to get weight=w
 
 base case:
 M[0, 0] = 0 (using 0 item to get weight 0, the total value is 0)
 M[0, 1]...M[0, w] = INT_MIN (no way to use 0 items to get weight > 0)
 
 induction rule:
 M[i, w] = max(M[i-1, w], m[i-1, w - weights[i] + v[i]])
 */

#include <vector>
#include <iostream>
using namespace std;

// time: O(NW), space: O(NW)
int getMaxTotalValue_classic(vector<int> weights, vector<int> values, int w){
    vector<vector<int>> dp(weights.size()+1, vector<int>(w+1, INT_MIN));
    dp[0][0] = 0;
    int res = INT_MIN;
    for(int i=1; i<=weights.size(); ++i){
        for(int j=w; j>=0; --j){
            if(j >= weights[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i-1]+values[i-1]]);
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            res = max(res, dp[i][j]);
        }
    }
    return res;
}
