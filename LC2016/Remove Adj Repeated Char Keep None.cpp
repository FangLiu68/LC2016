//
//  Remove Adj Repeated Char III.cpp
//  LC2016
//
//  Created by Fang Liu on 4/4/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Remove adjacent repeated characters in a given string, leaving no character for each group of such characters. The characters in the string are sorted in ascending order.
 
 Assumptions
 Try to do it in place.
 
 eg, "aaabbbc" -> "c"
 
 corner case: if the given string is null, we do not need ot do anything.
 */

#include <string>
#include <iostream>
using namespace std;

// all on left of slow (including input[slow]) are what we want
// 注意，这里也是slow的左边（包括slow）都是满足条件的部分
string deDupIII(string s) {
    // write your solution here
    if(s.size()<=1) return s;
    int slow = 0; // 快慢指针初始值必须不同，因为开始就需要根据index不同来判断开始的那部分是不是重复的
    int fast = 1;
    bool flag = false; // 此时slow代表的重复字符块已经完结
    while(fast < s.size()){
        // 如果是重复，则slow不动,fast一直++
        if(s[slow] == s[fast]){
            fast++;
            flag = true;
        }else if(flag == true){ // 如果slow和fast不同且slow代表的字符块没有完结，就需要让他完结（方法是将fast的值覆盖到slow），同时将flag设置回false（因为此时slow的字符块已经完结）
            // slow代表的之前的重复字符一个都不能留，所以当我们把s[fast]放到s[slow]的位置时，我们不知道这个新的字符是否可能将会继续重复，因为fast还没有scan到。所以fast++，而slow不能++。同时，因为flag代表的是slow之前的字符是否重复，而既然我们已经用新的fast将旧的slow覆盖了，就需要将flag设置为false。
            s[slow] = s[fast++];
            flag = false;
        }else{ // 如果slow和fast不同且slow代表的字符块已经完结，直接将fast覆盖到++slow即可
            s[++slow] = s[fast++];
        }
    }
    // flag设置成true的情况只可能是slow一直等于fast，直到fast出界
    // 即如果s=="aaaaa"，那么slow仍为0 不加1
    // 即如果flag==false，表明slow代表的之前的字符已经完结，应该+1
    if(!flag) slow++;
    return s.substr(0, slow);
}


/*
int main(){
    string input = "aaabbbcddddee";
    cout << deDupIII(input) << endl;
    return 0;
}*/