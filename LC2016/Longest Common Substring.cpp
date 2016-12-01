//
//  Longest Common Substring.cpp
//  LC2016
//
//  Created by Fang Liu on 11/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 s "abcd"
 t "bced"
 dp[i][j] is the longest common substring ending at s[i] and t[j]
 induction rule:
 dp[i][j] = dp[i-1][j-1] + 1 (if s[i]==t[j])
          = 0                (if s[i]!=t[j])
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int longestCommonSubstring(string s, string t){
    if(s.empty() || t.empty()){
        return 0;
    }

    vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
    int res = 0;

    for(int i=0; i < dp.size(); ++i){
        for(int j=0; j<dp[0].size(); ++j){
            if(s[i] == t[j]){
                if(i>0 && j>0){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = 1;
                }
            }
            res = max(res, dp[i][j]);
        }
    }

    return res;
}

/*
int main(){
    string s = "abcd";
    string t = "bced";
    cout << longestCommonSubstring(s, t) << endl;
    return 0;
}*/
