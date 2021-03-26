## Orbit Counting Programs
The [Collatz Conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture) is a simple problem that has bedevilled mathematicians for a very long time. In brief, pick any positive integer that is not 0, if it's even divide it by 2, if it's odd multiply it by 3 and add 1. Repeat this process ad infinitum, the conjecture asks if every number eventually reduces to 1. So far no counterexamples have been found and a lot of numbers have been tested, but there is no proof of the conjecture. This repository consists of two programs written in C using Netbeans that investigate the conjecture. 

### [Collatz Map](https://github.com/FuzzyBunnys/Collatz-Programs/tree/main/Collatz%20Map)
This program tests the first two hundred odd integers, though it can easily be extended by modifying the variable of the main for loop. The core function of the program counts the number of divisions by 2 after a multiplication by 3 for an input number.


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
    };'

### [Limited Collatz Map](https://github.com/FuzzyBunnys/Collatz-Programs/tree/main/Limited%20Collatz%20Map)
This program tests the first two hundred odd integers as well but it only counts as far as the number of binary digits in the initial number. It's output is similar to the program above for each odd number input it produces the following output.

    103 = ...1100111 { 1  1  2  1  1  1 }

Where 103, is the number in decimal notation and 1100111 is the number in binary notation. The values in the brackets { 1 1 2 1 1 1} are the numbers of divisions by 2 that took place after each multiplication by 3 and addition of 1. For example, since 103 is an odd number, we would input it into the Collatz Function and obtain the following result. 3 * 103 + 1 = 310, we then divide by 2 310/2 = 155. Since we have an odd number the next step is to multiply by 3, and so the first value in the brackets is { 1 ...}. In this limited program the sum of the digits in the brackets is equal to the binary digits of the initial number. So since 103 has 7 binary digits in its binary representation 1100111, the sum of the numbers in the brackets { 1 1 2 1 1 1} is 7. 


### But Why?
Obviously any reasonable person at this point is asking why anyone would want to do this. I was searching for patterns or classes of numbers that might obviously reduce to 1 in the Collatz Function. For example, if you look at the binary representation of a power of two (8 = 100). You will see immediately that any power of 2 will reduce to 1 since division by 2 in binary is equivalent to removing a 0 (just like division by 10 removes a 0 in decimal representation). If one thinks for a little bit, one can see that there is a class of number that when tripled and incremented by 1 become a power of 2. 5 * 3 + 1 = 16 is the smallest example of such a number, but there are lots of others (5, 21, 85 ...). In binary all of these odd numbers are of the form 10101..., if you double such a number and add it to itself in binary (2n +n = 3n) it becomes immediately apparent why these numbers behave in such a manner. 

   1010  
<ins>+  101<\ins> 
   1111  
[+    1]  
  10000  
               
