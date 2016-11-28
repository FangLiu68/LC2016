//
//  Naive Knapsack, get number of solutions.cpp
//  LC2016
//
//  Created by Fang Liu on 11/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a set of N items. each item has a weight weights[i](i=1...N). the knapsack has a weight capacity W. whats the total number of unique ways to exactly fill the knapsack?
 
 与P1的区别：P1只需要知道能不能达到某个weight，而P1a还要求方案总数
 
 example:
 w = 5
 weights[] = 2, 3, 5
 (a) 2 and 3; (b) 5
 total number of unique ways = 2
 
 solution:
 M[i, w]: by using the first i items, the total number of unique ways to get weight = w
 
 base case:
 M[0, 0] = 1 (there is only one way to use 0 items to get weight 0)
 M[0, 1]...M[0, w] = 0 (no way to use 0 items to get weight > 0)
 
 induction rule:
 M[i, w] = M[i-1, w] + M[i-1, w-weight[i]]
 
 对于求方案总数的问题，通常只需要将induction rule中的运算改为求和即可
 */
