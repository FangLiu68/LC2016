//
//  Binary Search in 2D Space.cpp
//  LC2016
//
//  Created by Fang Liu on 3/21/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 2D matrix, sorted on each row, first element of the next row is larger (or equal) to teh last element of previous row, now giving a target number, returning the position that the largest locates within the matrix.
 */

#include <vector>
#include <iostream>
using namespace std;

// convert 2D to 1D then do bianry search
// log(mn) time
vector<int> search_2D(vector<vector<int>> matrix, int target){
    vector<int> res;
    if(matrix.empty() || matrix[0].empty()){
        return res;
    }
    
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0;
    int right = row * col -1;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        int index_row = mid/col;
        int index_col = mid%col;
        if(matrix[index_row][index_col] == target){
            res.push_back(index_row);
            res.push_back(index_col);
            return res;
        }else if(matrix[index_row][index_col] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return res;
}

bool Search_2D(vector<vector<int>> matrix, int target){
    if(matrix.empty() || matrix[0].empty()){
        return false;
    }
    
    int row = matrix.size();
    int col = matrix[0].size();
    
    int left = 0;
    int right = row * col - 1;
    
    while(left <= right){
        int mid = left + (right-left)/2;
        int index_row = mid / col;
        int index_col = mid % col;
        
        if(matrix[index_row][index_col] == target){
            return true;
        }else if(matrix[index_row][index_col] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    
    return false;
}

/*
int main(){
    vector<int> row1 = {1, 3, 5, 7};
    vector<int> row2 = {10, 11, 16, 20};
    vector<int> row3 = {23, 30, 34, 50};
    vector<vector<int>> matrix = {row1, row2, row3};
    if(Search_2D(matrix, 1))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    
    return 0;
}
*/