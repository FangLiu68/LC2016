//
//  Search a 2D Matrix II.cpp
//  LC2016
//
//  Created by Fang Liu on 8/9/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Write an efficient algorithm that search for a value in an m*n matrix. This matrix has the following properties:
    integers in each row are sorted in ascending from left to right.
    integers in each column are sorted in ascending fro top to bottom.
 
 For example:
 [
 [1,   4,  7, 11, 15],
 [2,   5,  8, 12, 19],
 [3,   6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]
 ]
 Given target = 5, return true.
 Given target = 20, return false.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 time complexity O(N)
 space complexity O(1)
 */
bool searchMatrixII(vector<vector<int>>& matrix, int target){
    if(matrix.empty()) return false;
    
    int row = matrix.size();
    int col = matrix[0].size();
    
    int i = 0;
    int j = col - 1;
    
    while(i < row && j >=0){
        if(matrix[i][j] == target){
            return true;
        }else if(matrix[i][j] < target){
            i++;
        }else{
            j--;
        }
    }
    
    return false;
}

