/* 
 * File:   main.c
 * Author: taianluo
 *
 * Created on 2014年10月4日, 下午 4:18
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
typedef struct Ball {

    union {

        struct {
            unsigned testIa : 1;
            unsigned testIb : 1;
            unsigned testIc : 1;
            unsigned testId : 1;
            unsigned testIe : 1;
            unsigned testIf : 1;
            unsigned testIg : 1;
            unsigned testIh : 1;
        };

    };
} Ball;

Ball _ball;
Ball *ball;

int main(int argc, char** argv) {
    long int i, j;
    ball = &_ball;


    i = sizeof (j);
    j = 255;


    return (EXIT_SUCCESS);
}

