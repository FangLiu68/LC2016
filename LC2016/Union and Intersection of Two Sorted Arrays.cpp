//
//  Union and Intersection of Two Sorted Arrays.cpp
//  LC2016
//
//  Created by Fang Liu on 8/10/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given two sorted arrays, find their union and intersection:
 For example, if the input arrays are:
 arr1[] = {1, 3, 4, 5, 7}
 arr2[] = {2, 3, 5, 6}
 Then your program should print Union as {1, 2, 3, 4, 5, 6, 7} and Intersection as {3, 5}.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 time complextiy O(m + n)
 space complexity O(1)
 */

vector<int> union_of_twoArr(vector<int>& input1, vector<int>& input2){
    vector<int> res;
    if(input1.empty()){
        return input2;
    }else if(input2.empty()){
        return input1;
    }
    
    int index1 = 0;
    int index2 = 0;
    
    while(index1 < input1.size() && index2 < input2.size()){
        if(input1[index1] < input2[index2]){
            res.push_back(input1[index1]);
            index1++;
        }else if(input1[index1] > input2[index2]){
            res.push_back(input2[index2]);
            index2++;
        }else{
            res.push_back(input1[index1]);
            index1++, index2++;
        }
    }
    
    if(!input1.empty()){
        while(index1 < input1.size()){
            res.push_back(input1[index1++]);
        }
    }
    
    if(!input2.empty()){
        while(index2 < input2.size()){
            res.push_back(input2[index2++]);
        }
    }
    
    return res;
}

vector<int> intersection_of_twoArr(vector<int>& input1, vector<int>& input2){
    vector<int> res;
    if(input1.empty() || input2.empty()){
        return res;
    }
    
    int index1 = 0;
    int index2 = 0;
    
    while(index1 < input1.size() && index2 < input2.size()){
        if(input1[index1] < input2[index2]){
            index1++;
        }else if(input1[index1] > input2[index2]){
            index2++;
        }else{
            res.push_back(input1[index1]);
            index1++, index2++;
        }
    }
    
    return res;
}
/*
int main(){
    vector<int> input1 = {1, 3, 4, 5, 7};
    vector<int> input2 = {2, 3, 5, 6};
    
    vector<int> res_union = union_of_twoArr(input1, input2);
    vector<int> res_intersection = intersection_of_twoArr(input1, input2);
    
    for(int i=0; i<res_union.size(); ++i){
        cout << res_union[i] << " ";
    }
    cout << endl;
    
    for(int i=0; i<res_intersection.size(); ++i){
        cout << res_intersection[i] << " ";
    }
    cout << endl;
    
    return 0;
}
*/
