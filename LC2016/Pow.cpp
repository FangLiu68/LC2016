//
//  Pow.cpp
//  LC2016
//
//  Created by Fang Liu on 4/5/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// implement pow(x, n)

#include <iostream>
using namespace std;

double pow(double x, int n){
    // base case
    if(n == 0){
        return 1;
    }
    
    double v = pow(x, n/2);
    
    if(n % 2 == 0){
        return v * v;
    }else{
        return v * v * x;
    }
}

double myPow(double x, int n) {
    if(n < 0){
        return 1 / pow(x, -n);
    }else{
        return pow(x, n);
    }
}

