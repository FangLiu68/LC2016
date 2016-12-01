//
//  Longest Common Subsequence.cpp
//  LC2016
//
//  Created by Fang Liu on 11/30/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Longest Common Subsequence
 
 s = "abcd"
 t = "bced"
 M[i][j] = M[i-1][j-1] + 1              (if s[i]==t[j])
         = max(M[i-1][j], M[i][j-1])    else
 
    a   b   c   d
 b  0   1   1   1
 c  0   1   2   2
 e  0   1   2   2
 d  0   1   2   3
 
    b   c   e   d
 a  0   0   0   0
 b  1   1   1   1
 c  1   2   2   2
 d  1   2   2   3
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
 base case:
 M[0][0] = 0    if(s[0]==t[0])
         = 1    else
 */

int longestCommonSubsequence(string s, string t){
    if(s.empty() || t.empty()){
        return 0;
    }

    vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));

    if(s[0] == t[0]){
        dp[0][0] = 1;
    }else{
        dp[0][0] = 0;
    }
    for(int i=1; i<s.size(); ++i){
        if(s[i] == t[0]){
            dp[i][0] = dp[i-1][0] + 1;
        }else{
            dp[i][0] = dp[i-1][0];
        }
    }
    for(int j=1; j<t.size(); ++j){
        if(t[j] == s[0]){
            dp[0][j] = dp[0][j-1] + 1;
        }else{
            dp[0][j] = dp[0][j-1];
        }
    }

    for(int i=1; i<s.size(); ++i){
        for(int j=1; j<t.size(); ++j){
            if(s[i] == t[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[s.size()-1][t.size()-1];
}

int main(){
    string s = "a";
    string t = "bced";
    cout << longestCommonSubsequence(s, t) << endl;
    return 0;
}
