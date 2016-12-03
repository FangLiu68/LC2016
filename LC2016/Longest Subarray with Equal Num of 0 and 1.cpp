//
//  Longest Subarray with Equal Num of 0 and 1.cpp
//  LC2016
//
//  Created by Fang Liu on 12/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given 1, 0 array, find the longest subarray contains equal number of 0 and 1.
 index  -1  0  1  2  3  4  5  6
 array      1  0  1  1  0  0  1
 replace    1 -1  1  1 -1 -1  1
 preSum  0  1  0  1  2  1  0  1
 
 step 1: create a new array copy 1s and record 0 as -1
 step 2: calculate prefix sum array for the new array
 step 3: find the longest length with prefix sum == 0
 
 用map<int,int>来存储从index=0开始走，一直走到index=i为止的<preSum, i>
 注意：我们在map里initialize初始值<0, -1>，假设preSum=0时的index为-1
 如果在当前index下计算出的preSum之前没有出现过，则将<preSum, i>存入map
 如果在当前index下计算出的preSum已经存入了map，说明此preSum增加或者减少一段时间后，又恢复原值了。即preSum增加/减少的这段subarray里，包含相同数量的0或者1.因此，我们只用将当前preSum的index，减去之前出现的相同preSum的index，就得到了数量相同0/1的subarray。
 假设对于preSum，先后出现的index为i, j。则我们需要的subarray为(i, j].注意这里包含j不包含i，仔细体会一下。
 注意：
 1. 用map来存<presum, index>是为了快速找到具有相同presum的index
 2. 当发现preSum有重复时，不需要更新map里index的值。因为我们要求的是最长subArray.
 3. 将原数组中的0替换为-1是为了便于区分哪个index是0（因为任何数+0都不变）。我们也可以用-2，-3等任意其他非1非0的值来替换0.
 
 对于本例子，满足条件的longest subarray有两个。index[0...5] 和 index[1...6]
 大小为6.
 
 Time: O(N)
 Space: O(N) + O(N) = O(N)
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int longestSubarrWithEqual01(vector<int> arr){
    if(arr.empty()){
        return 0;
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    vector<int> preSum(arr.size());
    int sum = 0;
    int longest = 0;
    for(int i=0; i<arr.size(); ++i){
        if(arr[i] == 1){
            sum += 1;
        }else{
            sum -= 1;
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }else{
            longest = max(longest, i-mp[sum]);
        }
    }
    return longest;
}
/*
int main(){
    vector<int> arr = {1, 0, 1, 1, 0, 0, 1, 0, 1};
    cout << longestSubarrWithEqual01(arr) << endl;
    return 0;
}
*/
