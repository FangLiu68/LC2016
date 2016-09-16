//
//  Find the Duplicate Number.cpp
//  LC2016
//
//  Created by Fang Liu on 8/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array nums containing n+1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 
 Note:
 You must not modify the array (assume the array is read only).
 You must use only constant, O(1) extra space.
 Your runtime complexity should be less than O(n2).
 There is only one duplicate number in the array, but it could be repeated more than once.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 证明至少存在一个重复元素 -- 是鸽笼原理的直接应用。
 如果元素的范围是[1, n], 那么只存在n种不同的值。如果有n+1个元素，其中一个必然重复。
 */
 
 /*
 映射找环法：time O(N), space O(1)
 假设数组中没有重复，那我们可以做到这么一点，就是将数组的下标和1到n每一个数一对一的映射起来。比如数组是213,则映射关系为0->2, 1->1, 2->3。假设这个一对一映射关系是一个函数f(n)，其中n是下标，f(n)是映射到的数。如果我们从下标为0出发，根据这个函数计算出一个值，以这个值为新的下标，再用这个函数计算，以此类推，直到下标超界。实际上可以产生一个类似链表一样的序列。比如在这个例子中有两个下标的序列，0->2->3。
 
 但如果有重复的话，这中间就会产生多对一的映射，比如数组2131,则映射关系为0->2, {1，3}->1, 2->3。这样，我们推演的序列就一定会有环路了，这里下标的序列是0->2->3->1->1->1->1->...，而环的起点就是重复的数。
 
 所以该题实际上就是找环路起点的题，和Linked List Cycle II一样。我们先用快慢两个下标都从0开始，快下标每轮映射两次，慢下标每轮映射一次，直到两个下标再次相同。这时候保持慢下标位置不变，再用一个新的下标从0开始，这两个下标都继续每轮映射一次，当这两个下标相遇时，就是环的起点，也就是重复的数。对这个找环起点算法不懂的，请参考Floyd's Algorithm。 
  
  
  二分法：
  时间 O(NlogN) 空间 O(1)
  思路
  实际上，我们可以根据抽屉原理简化刚才的暴力法。我们不一定要依次选择数，然后看是否有这个数的重复数，我们可以用二分法先选取n/2，按照抽屉原理，整个数组中如果小于等于n/2的数的数量大于n/2，说明1到n/2这个区间是肯定有重复数字的。比如6个抽屉，如果有7个袜子要放到抽屉里，那肯定有一个抽屉至少两个袜子。这里抽屉就是1到n/2的每一个数，而袜子就是整个数组中小于等于n/2的那些数。这样我们就能知道下次选择的数的范围，如果1到n/2区间内肯定有重复数字，则下次在1到n/2范围内找，否则在n/2到n范围内找。下次找的时候，还是找一半。
  注意
  我们比较的mid而不是nums[mid]
  因为mid是下标，所以判断式应为cnt > mid，最后返回min
 */
int findDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2; // 找到中间那个数
        
        // 计算数组中有多少数小于等于中间数
        int count = 0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i] <= mid){
                ++count;
            }
        }
        
        // 如果小于等于中间数的数量大于中间数，说明前半部分有重复
        if(count > mid){
            right = mid - 1;
        }else{ // 后半部分有重复
            left = mid + 1;
        }
    }
    return left;
}
/*
int main(){
    vector<int> input = {3, 1, 2, 1};
    int res = findDuplicate(input);
    cout << res << endl;
    return 0;
}*/