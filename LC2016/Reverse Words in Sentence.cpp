//
//  Reverse Words in Sentence.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Reverse the words in a sentence.
 
 Assumptions
 Words are separated by single space
 There are no heading or tailing white spaces
 Examples
 “I love Google” → “Google love I”
 Corner Cases
 If the given string is null, we do not need to do anything.
 */

#include <string>
#include <iostream>
using namespace std;

/*
 1. swap the whole sentence
 2. swap every single word
 */
void helper_reverse(string& input, int left, int right){
    while(left <= right){
        char t = input[left];
        input[left++] = input[right];
        input[right--] = t;
    }
}

string reverse_word_in_string(string input){
    if(input.empty()){
        return " ";
    }
    
    helper_reverse(input, 0, input.size()-1);
    
    int start = 0;
    for(int i=0; i<input.size(); ++i){
        if(input[i] == ' '){
            helper_reverse(input, start, i-1);
            start = i + 1;
        }
    }
    
    if(input[input.size()-1] != ' '){
        helper_reverse(input, start, input.size()-1);
    }
    
    return input;
}

//========================
// 下面的做法要重新想，因为下面的做法用不着helper_reverse的话
void reverse_words(string& input){
    string res;
    if(input.empty()){
        return;
    }
    
    //helper_reverse(input, 0, input.size()-1);
    reverse(input.begin(), input.end());
    
    for(int i=0; i<input.size(); ++i){
        while(input[i] == ' '){
            i++;
        }
        if(i == input.size()) break;
        if(!res.empty()){
            res.push_back(' ');
        }
        string temp;
        while(input[i] != ' ' && i < input.size()){
            temp.push_back(input[i]);
            i++;
        }
        reverse(temp.begin(), temp.end());
        res.append(temp);
    }
    input = res;
}
/*
int main(){
    string input = "I love Google";
    reverse_words(input);
    cout << input << endl;
    return 0;
}*/