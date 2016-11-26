//
//  Permutation No Dup.cpp
//  LC2016
//
//  Created by Fang Liu on 4/18/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a string with no duplicate characters, return a list with all permutaions of the characters.
 
 Examples:
 Set = "abc", all permutations are ["abc", "acb", "bac", "bca", "cab", "cba"]
 Set = "", all permutations are [""]
 Set = null, all permutations are []
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void swap_permuNoDup(string& input, int i, int index){
    if(i == index) return;
    char temp = input[i];
    input[i] = input[index];
    input[index] = temp;
}

void helper_permuNoDup(string& input, vector<string>& res, int index){
    if(index == input.size()){
        res.push_back(input);
        return;
    }
    
    for(int i = index; i < input.size(); ++i){
        swap_permuNoDup(input, index, i);
        helper_permuNoDup(input, res, index+1);
        swap_permuNoDup(input, index, i);
    }
}

vector<string> permutationNoDup(string input){
    vector<string> res;
    if(input.empty()){
        return res;
    }
    
    helper_permuNoDup(input, res, 0);
    return res;
}


//===============================
void findPermutations(vector<int>& input, vector<bool>& used, vector<int>& per, vector<vector<int>>& allPer){
    if(per.size() == input.size()){
        allPer.push_back(per);
        return;
    }
    
    for(int i=0; i<=2; ++i){
        if(used[i]){
            continue;
        }
        used[i] = true;
        per.push_back(input[i]);
        findPermutations(input, used, per, allPer);
        used[i] = false;
        per.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& input){
    vector<vector<int>> allPer;
    if(input.empty()){
        return allPer;
    }
    vector<bool> used(input.size(), false);
    vector<int> per;
    findPermutations(input, used, per, allPer);
    return allPer;
}
/*
int main(){
    string input = "abc";
    vector<string> res = permutationNoDup(input);
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << " ";
    }cout << endl;
    return 0;
}
*/
