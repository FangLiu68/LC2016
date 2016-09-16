//
//  Bucket Sort.cpp
//  LC2016
//
//  Created by Fang Liu on 8/12/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Suppose we need to sort an array of positive integers {3,11,2,9,1,5}. A bucket sort works as follows: create an array of size 11. Then, go through the input array and place integer 3 into a second array at index 3, integer 11 at index 11 and so on. We will end up with a sorted list in the second array.
 
 Suppose we are sorting a large number of local phone numbers, for example, all residential phone numbers in the 412 area code region (about 1 million) We sort the numbers without use of comparisons in the following way. Create an a bit array of size 107. It takes about 1Mb. Set all bits to 0. For each phone number turn-on the bit indexed by that phone number. Finally, walk through the array and for each bit 1 record its index, which is a phone number.
 
 We immediately see two drawbacks to this sorting algorithm. Firstly, we must know how to handle duplicates. Secondly, we must know the maximum value in the unsorted array.. Thirdly, we must have enough memory - it may be impossible to declare an array large enough on some systems.
 
 The first problem is solved by using linked lists, attached to each array index. All duplicates for that bucket will be stored in the list. Another possible solution is to have a counter. As an example let us sort 3, 2, 4, 2, 3, 5. We start with an array of 5 counters set to zero.
 
 0   1   2   3   4   5
 0	 0	 0	 0	 0	 0
 Moving through the array we increment counters:
 0   1   2   3   4   5
 0	 0	 2	 2	 1	 1
 Next,we simply read off the number of each occurrence: 2 2 3 3 4 5.
 */