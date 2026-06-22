/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04
    
    PURPOSE OF THIS FILE: Performs the graham's scan algorithm using insertion function and stack operations used.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/
#include "sort.c"
#include "stack.c"
#include "stackhelper.c"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: Performs the graham's scan algorithm
    e. Return: none
    f. Parameters: long int *N - the size of the stack and the amount of elements in it
    		   stack *S - is the struct that will act as the stack
*/
void cv(long int *N, stack *S)
{
    int size, i;
    size = S->top + 1;

    findAnchorPoint(S->coords, size);
    insertionSort(S->coords, size);

    *N = size;

    printf("%d", stackEmpty(&*S));

    if (!stackEmpty(&*S))
    {
        i = 0;
        int ceiling = S->top + 1;

        lowestPoint(S->coords, ceiling);

        S->top = 1;
        i = 2;

        while (i < ceiling)
        {

            // you can implement a function to flip the order so that the lowest leftmost pt
            // can be at the top of the stack but its gonna make ts 100000x slower so idk

            Point top = Top(&*S);
            Point secondTop;

            if (S->top > 0)
                secondTop = nextToTop(&*S);
            else
                secondTop = top;
                
            Point next = S->coords[i];

            if (S->top == 0 || orientation(next, top, secondTop) < 0)
            {
                i++;
                Push(&*S, next);
            }
            else
            {
                Pop(&*S);
            }
        }
    }
}