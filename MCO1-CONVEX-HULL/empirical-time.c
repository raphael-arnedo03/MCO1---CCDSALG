/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04

    PURPOSE OF THIS FILE: Holds the programs for the stacking operations

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/
/*
   empirical-time.c

   Sample program for determining the empirical execution time. Note that the actual numerical results will depend on the platform,
   i.e., the hardware, the compiler, the operating system.
*/

#include <stdio.h>
#include <time.h>    // this is needed for calling the clock()
/*#include "graham_slow.c"*/
#include "graham_fast.c"

#define STEP  (1024)
#define LIMIT (32768)

// NOTE: 2^10 = 1024 for the STEP
//       2^15 = 32768 for the LIMIT

//
// this is a sample algo, it is O(n^2) as it contains a loop within a loop
//
// parameter n is the problem (or input) size
void algo(long int n)
{
  clock_t the_start; // start time 
  clock_t the_end;   // end time

  the_start = clock();  // record the start time 

  stack S;
  Create(&S);
  importTxtAuto(&S, 3); //Set number to test file number
  cv(&n, &S);
  
  the_end = clock();  // record the end time

  // prints the input size n and the corresponding elapsed execution time in ms (millisecond)
  //printf("size time: %6ld %15lf\n", n, (double)(the_end - the_start));
  printf("time in ms: %15lf\n", (double)(the_end - the_start));  
}

int main() {
  long int n;        // n is the problem or input size

  // generates the problem size n, each n is a power of 2  
  for (n = 0; n <= LIMIT; n += STEP) {  
     algo(n);
  }  

  return 0;
}
