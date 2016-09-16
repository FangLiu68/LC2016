#include <vector>
#include <iostream>
using namespace std;

void test_bubble_sort(vector<int>& input){
    if(input.empty()){
        return;
    }
    
    for(int i=0; i<input.size()-1; ++i){
        for(int j=i+1; j<input.size(); ++j){
            if(input[i] > input[j]){
                // swap input[i] input[j]
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
}

void test_insertion_sort(vector<int>& input){
    if(input.empty()){
        return;
    }
    
    
}

void test_selection_sort(vector<int>& input){
    if(input.empty()){
        return;
    }
    
    
}