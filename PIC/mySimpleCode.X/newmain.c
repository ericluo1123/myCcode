/* 
 * File:   newmain.c
 * Author: taianluo
 *
 * Created on 2014年10月6日, 下午 4:10
 */

#include <stdio.h>
#include <stdlib.h>
#define true 1
/*
 * 
 */
int main(int argc, char** argv) {

    unsigned char i;
    while (true) {
        i=~i & 0x01;
    }

    return (EXIT_SUCCESS);
}

