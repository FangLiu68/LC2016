//
//  Subarrays Sum to 0.cpp
//  LC2016
//
//  Created by Fang Liu on 9/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of integers, find the number of subarrays whose sum equals to 0.
 
 Example:
 input [0, 1, 3, -4, -1, 0, 1]

 result:
 [0]
 [0, 1, 3, -4]
 [0, 1, 3, -4, 1, 0, -1]
    [1, 3, -4]
    [1, 3, -4, 1, 0, -1]
              [1, 0, -1]
                 [0]
 */

/*
 this is a prefix-sum problem (DP III)
 */
