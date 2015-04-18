/* 
 * File:   Main.c
 * Author: Patrick
 *
 * Created on 2015年4月11日, 上午 11:02
 */

#include "Main.h"

typedef struct {

    int a, b;
    long aa, bb, cc, dd, ee, ff;

} test;

typedef struct {
    int (*ptr)(test*);
    test aa;
}test1;

void setTest(test*);

int abc(test1*);

int abc(test1 *aaa) {

    return aaa->aa->a=0;
//    return aaa->a = 5;
}

void setTest(test *p) {
//    p->a = 1;
}

/*
 * Main
 */
int main(int argc, char** argv) {

#if Use_Chip == 1

#endif
    int tt;
    test1 ttt;
    ttt.ptr=abc;


//    t1.ptr=;
//    tt = t1.ptr();

    int yy;
//    yy = t1.a;
    while (1) {



    }



    return (EXIT_SUCCESS);
}

