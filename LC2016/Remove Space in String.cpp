//
//  Remove Space in String.cpp
//  LC2016
//
//  Created by Fang Liu on 4/3/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Remove all leading/trailing and duplicate empty spaces from the input string.
 
 input   = “    abc      ed    ef    ”;
 output = “abc ed ef”;
 */

#include <string>
#include <iostream>
using namespace std;

void removeSpace(string& input){
    if(input.empty()){
        return;
    }
    
    int slow = 0;
    int fast = 0;
    bool add_space = false;
    
    while(fast < input.size()){
        while(input[fast]==' ' && fast<input.size()){
            fast++;
        }
        
        if(fast == input.size()){
            break;
        }
        
        if(add_space){
            input[slow++] = ' ';
        }
        
        while(fast<input.size() && input[fast] != ' '){
            input[slow++] = input[fast++];
        }
        
        add_space = true;
    }
    
    input.resize(slow);
}
