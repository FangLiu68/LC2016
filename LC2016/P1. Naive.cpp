//
//  1 knapsack problem.cpp
//  LC2016
//
//  Created by Fang Liu on 11/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a set of N items. Each item has a weight weights[i](i=1...N). The knapsack has a weight capacity W. Whats the maximum total weight you can get?
 example:
 W = 8
 weights[] = 4, 3, 5
 
 lets use boolean M[i, w] to represent whether we can get weight=w by using the first i items.
 M[2, 5] = false
 M[2, 7] = true
 
 base case:
 M[0, 0] = true (you can always use 0 items to get weight 0)
 M[0, 1]...M[0, N] = false (you can't use 0 items to get weight > 0)
 
 induction rule?
 M[i, w]: we are looking at the i-th item (its weight is weights[i])
 只有两种情况：第i个item取或者不取
 如果不取的话，也就是前i-1个items已经能够达到weight=w了
 如果取的话，也就是通过前i-1个items还差weights[i]才能达到weight = w
 M[i, w] = M[i-1, w] || M[i-1, w-weight[i]]
 
 solution:
 M[i, w]: by using the first i items, whether we can get weight = w
 base case: M[0, 0] = true
            M[0, 1]...M[0, w] = false
 induction rule: M[i, w] = M[i-1, w] || M[i-1, w-weights[i]]
 
 Time: O(NW)
 Space: O(NW)
 */

/*
 NOTE:
 vector<vector <int> > ivec(m ,vector<int>(n));   //m*n的二维vector
 vector<vector <int> > ivec(m ,vector<int>(n,0)); //m*n的二维vector，所有元素初始化为0
 */

#include <vector>
#include <iostream>
using namespace std;

int getMaxTotalWeight(vector<int> weights, int w){
    vector<vector<bool>> dp(weights.size()+1, vector<bool>(w+1, false));
    dp[0][0] = true;
    int res = INT_MIN;

    for(int i=1; i<=weights.size(); ++i){
        for(int j=w; j>=0; --j){
            if(j >= weights[i-1]){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-weights[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
            if(i == weights.size() && dp[i][j]){
                res = max(res, j);
            }
        }
    }

    return res;
}


/*
 Solution 2
 space complexity O(w)
 M[i] only depends on M[i-1], we can just use currM[w] and preM[w]
 */
/*
int getMaxTotalWeight2(vector<int> weights, int w){
    vector<bool> curM(w+1, false);
    vector<bool> preM(w+1, false);
    preM[0] = true;
    int res = INT_MIN;

    for(int i=1; i<=weights.size(); ++i){
        for(int j=w; j>=0; --j){
            curM[j] = preM[j] || preM[j-weights[i-1]];
            if(i == weights.size() && curM[j]){
                res = max(res, j);
            }
        }
        for(int j=0; j<=w; ++j){
            preM[j] = curM[j];
        }
    }

    return res;
}*/
/*
int main(){
    vector<int> weights = {4, 3, 5};
    int w = 8;
    int res = getMaxTotalWeight(weights, w);
    cout << res << endl;
    return 0;
}

*/

