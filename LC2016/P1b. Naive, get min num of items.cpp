//
//  P1b. Naive, get min num of items.cpp
//  LC2016
//
//  Created by Fang Liu on 11/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a set of N items. each item has a weight weights[i](i=1...N). the knapsack has a weight capacity W. whats the minimum number of items needed to exactly fill the knapsack?
 
 与P1的区别：
 P1只需要知道能不能达到某个weight, P1b还要求item数目最少
 
 example:
 w = 5
 weights[] = 2, 3, 5
 (a) 2 and 3
 (b) 5
 minimum number of items = 1
 
 solution of P1b:
 M[i, w]: by using the first i items, the minimum number of items to get weight = w
 
 base case:
 M[0, 0] = 0 (use 0 item to get weight 0)
 M[0, 1]...M[0, w] = ?
 由于题目要求exactly fill, 所以M[0, 1]...M[0, w]都是不合法的
 M[0, 1]...M[0, w] = INT_MAX
 
 induction rule:
 M[i, w] = min(M[i-1, w], M[i-1, w-weight[i]] + 1)
 */
