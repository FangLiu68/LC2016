//
//  Set Matrix Zeros.cpp
//  LC2016
//
//  Created by Fang Liu on 7/23/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a m*n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m+n) space, but still not the best solution.
 Could you devise a constant space solution?
 
 */

#include <iostream>
#include <vector>
using namespace std;

// time O(m*n), space O(1)
void setZeroes(vector<vector<int>>& matrix) {
    if(matrix.empty()) return ;
    
    bool row_zero = false;
    bool column_zero = false;
    
    int row = matrix.size();
    int column = matrix[0].size();
    
    for(int i=0; i<row; ++i){
        if(matrix[i][0] == 0){
            row_zero = true;
            break;
        }
    }
    
    for(int i=0; i<column; ++i){
        if(matrix[0][i] == 0){
            column_zero = true;
            break;
        }
    }
    
    for(int i=1; i<row; ++i){
        for(int j=1; j<column; ++j){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for(int i=1; i<row; ++i){
        for(int j=1; j<column; ++j){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    
    if(row_zero){
        for(int i=0; i<row; ++i)
            matrix[i][0] = 0;
    }
    if(column_zero){
        for(int i=0; i<column; ++i)
            matrix[0][i] = 0;
    }
}