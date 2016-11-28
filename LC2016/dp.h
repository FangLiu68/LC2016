//
//  dp.h
//  LC2016
//
//  Created by Fang Liu on 11/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

#ifndef dp_h
#define dp_h

/*
 A quick review of dynamic programming 

 DP的核心思想类似于我们高中学习的数学归纳法：
 1. 把一个大问题（size=n）的解决方案用比他小的问题（们）来解决，也就是思考从问题size=n-1增加到size=n的时候，如何用小问题的solution构建大问题的solution.
 2. 与recursion的关系：
    a. recursion从大到小来解决问题，不记录任何sub-solution,只要考虑
        i.  recursive rule
        ii. base case
    b. DP从小到大来解决问题，记录sub-solution
        i.  induction rule: 由 size<n 的 subsolution => size=n 的 solution
        ii. base case

 常用方法：左大段+右小段 思想
 左大段：subsolution (size < n)，历史上数据告诉你
 右小段：直接已知的数据
 */

#endif /* dp_h */
