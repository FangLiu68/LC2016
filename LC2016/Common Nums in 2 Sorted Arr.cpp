//
//  Common Nums in 2 Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/2/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find common elements in two sorted arrays
 A[m] = 1, 2,3 , 4, 5
 B[n] = 4, 5, 6
 */

/*
 1. hash all elements from one array to hashtable, then check the other array
 hash the shorter array into hash table
 O(m+n)
 2. use two index move together
 */

// 注意，找intersection和找union是不一样的。找intersection, 只要任意一个数组查找完毕，就可以结束查找。但是找union,一定要把所有数组查找完毕。所以对于找union of two sorted arr来说，while(lenA && lenB)之后，还要继续找while(lenA), while(lenB)

#include <vector>
#include <iostream>
using namespace std;

// O(m+n) runtime, O(1) space
// 注意这里runtime O(m+n), eg: a[]={1,2,99}, b[]={3,4,...100}
vector<int> common_elem_in_two_sorted_arr(int A[], int lenA, int B[], int lenB){
    vector<int> res;
    if(A==NULL || B==NULL || lenA<=0 || lenB<=0) return res;
    int indexA = 0;
    int indexB = 0;
    while(indexA <= lenA && indexB <= lenB){
        if(A[indexA] == B[indexB]){
            res.push_back(A[indexA]);
            indexA++;
            indexB++;
        }
        else if(A[indexA] < B[indexB])
            indexA++;
        else
            indexB++;
    }
    return res;
}

/*
 或者用bianry search
 a[10]
 b[1 billion]
 we need to figure out which array is shorter. O(alogb)
 */