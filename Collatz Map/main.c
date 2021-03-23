/*
 * This program produces a map of the Collatz function for odd integers
 * from 3 to 199. First the number is written out in binary and then 
 */

/* 
 * File:   main.c
 * Author: fuzzy
 *
 * Created on March 30, 2018, 4:44 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


/*
 * 
 */
int main(int argc, char** argv) {
    
    char b[100]; // array for printing out my binary number
    int oddsteps, length;
    int setarray[100];
    printf("  Decimal:  Binary:    Map:\n");
   
    // so first I want to increment through say the 1st two hundred positive odd integers
    for(int i=3; i<=200; i+=2){ 
         
        inttobinary(i,b); 
        
        length=strlen(b); //so I want to count binary digits to establish my value for m - this is working here
        
        oddsteps = divbytwo(i,setarray,length);//then I want to count how many div/2 I can complete and write to my array
       
        printf("%9d = " ,i); //print out the number in decimal
        
        for(int a= length-1; a>=0; a--){ // print out my number in binary
            printf("%c", b[a]);
        }
        
        printf("%6 {");
     
        for(int j=0; j<= oddsteps; j++){ // print out the values of the array
            printf(" %d ", setarray[j]);
        }
        printf("}\n"); // new line
        
        oddsteps = 0; // reset
        
        for(int i=0; i<100; i++){// reset my array
            setarray[i]=0;
        }
    }
    

    return (EXIT_SUCCESS);
} //Not everything is correctly calculated atm


