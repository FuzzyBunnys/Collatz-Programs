## Orbit Counting Programs
The [Collatz Conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture) is a simple problem that has bedevilled mathematicians for a very long time. In brief, pick any positive integer that is not 0, if it's even divide it by 2, if it's odd multiply it by 3 and add 1. Repeat this process ad infinitum, the conjecture asks if every number eventually reduces to 1. So far no counterexamples have been found and a lot of numbers have been tested, but there is no proof of the conjecture. This repository consists of two programs written in C using Netbeans that investigate the conjecture. 

### [Collatz Map](https://github.com/FuzzyBunnys/Collatz-Programs/tree/main/Collatz%20Map)
This program tests the first two hundred odd integers, though it can easily be extended by modifying the variable of the main for loop. The core function of the program counts the number of divisions by 2 after a multiplication by 3. 
'int divbytwo(int num, int array[], int numzeros) { // gotta count the div by 2
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
    };'

### [Limited Collatz Map](https://github.com/FuzzyBunnys/Collatz-Programs/tree/main/Limited%20Collatz%20Map)
This program tests the first two hundred odd integers as well but it only counts as far as the number of binary digits in the initial number.
