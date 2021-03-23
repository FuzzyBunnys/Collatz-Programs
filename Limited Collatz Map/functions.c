/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <math.h>

int divbytwo(int num, int array[], int numzeros) { // gotta count the div by 2
    int arraycount = 0;
    int stepvalue = 0;
    int arraysum = 0;

    num = num * 3 + 1; // change odd to even via odd collatz step

    while (num != 1) {

        if (arraysum == numzeros) {//exit our loop if we have the right value in our array
            arraysum = 0; // reset
            break; // exit the while loop
        }
        if (num % 2 == 0) { //test if number is even
            stepvalue++;
            num = num / 2; // even collatz step
            array[arraycount] = stepvalue;

        } else { // if not even number is odd
            
            stepvalue = 0;

            num = num * 3 + 1;

            arraycount++;
        }
        
        arraysum = 0; // reset to 0 before I retest
        
        for (int i = 0; i <= 99; i++) { // need to sum my array here
            arraysum+= array[i];
        }
    }

    array[arraycount] = stepvalue; // is this necessary? I think sooo, don't touch it right now

    return arraycount;


    // and pass out the new odd after it's been divided by 2

};

void inttobinary(int num, char *p) { // print stuff in binary

    char * pStr = p; // setup a pointer to p

    if (NULL == p) {
        return;
    }

    do {
        if (num % 2 == 0) {
            *p = '0';
        } else {
            *p = '1';
        }

        p++; // increment the address of p

        num = num / 2;

    } while (num > 0);

    *p = '\0';
    // reverse the value of my string - gotta figure out how to do this
};