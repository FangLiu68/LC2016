//
//  Min Races.cpp
//  LC2016
//
//  Created by Fang Liu on 8/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given: 25 horses, a track of 5 lanes (a reace can only take 5 horses)
 Challenge: find the fastest 3 horses with minimum races
 Tell me the minimum number
 */

/*
 25 = 5*5, dived horses into 5 groups and suppose the following are the result:
 1  > 2  > 3  > 4  > 5
 6  > 7  > 8  > 9  > 10
 11 > 12 > 13 > 14 > 15
 16 > 17 > 18 > 19 > 20
 21 > 22 > 23 > 24 > 25
 
 Now lets have the sixth match between the winners and without loss of generality suppose the follow is the result
 1 > 6 > 11 > 16 > 21
 
 so the fastest three horses can only be from
 1 > 2 > 3
 6 > 7
 11
 
 1 is the fastest. we only need to have a match between 2 3 6 7 11 and find out the other two fastest.
 */