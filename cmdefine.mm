//
//  cmdefine.cpp
//  testCM
//
//  Created by xusea on 16/1/17.
//  Copyright © 2016年 xusea. All rights reserved.
//

#include <stdio.h>
#include "cmdefine.h"
cv::Point const DIRECTION4[5] = {
    Point(1,  0), //Direction 0: right
    Point(0,  1), //Direction 1: bottom
    Point(-1, 0), //Direction 2: left
    Point(0, -1), //Direction 3: up
    Point(0, 0),
};  //format: {dx, dy}

cv::Point const DIRECTION8[9] = {
    Point(1,  0), //Direction 0
    Point(1,  1), //Direction 1
    Point(0,  1), //Direction 2
    Point(-1, 1), //Direction 3
    Point(-1, 0), //Direction 4
    Point(-1,-1), //Direction 5
    Point(0, -1), //Direction 6
    Point(1, -1),  //Direction 7
    Point(0, 0),
};  //format: {dx, dy}

cv::Point const DIRECTION16[17] = {
    Point(2,  0), //Direction 0
    Point(2,  1), //Direction 1
    Point(2,  2), //Direction 2
    Point(1,  2), //Direction 3
    Point(0,  2), //Direction 4
    Point(-1, 2), //Direction 5
    Point(-2, 2), //Direction 6
    Point(-2, 1), //Direction 7
    Point(-2, 0), //Direction 8
    Point(-2,-1), //Direction 9
    Point(-2,-2), //Direction 10
    Point(-1,-2), //Direction 11
    Point(0, -2), //Direction 12
    Point(1, -2), //Direction 13
    Point(2, -2), //Direction 14
    Point(2, -1),  //Direction 15
    Point(0, 0),
}; //format: {dx, dy}

float const DRT_ANGLE[8] = {
    0.000000f,
    0.785398f,
    1.570796f,
    2.356194f,
    3.141593f,
    3.926991f,
    4.712389f,
    5.497787f
};

float const PI_FLOAT = 3.1415926535897932384626433832795f;
float const PI2 = PI_FLOAT * 2.0f;
double const Cm2PI = CV_PI * 2.0;
float const PI_HALF = PI_FLOAT * 0.5f;
double const SQRT2 = sqrt(2.0);
bool dbgStop = false;

double dummyD;
int dummyI;