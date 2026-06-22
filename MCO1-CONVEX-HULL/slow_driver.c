/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04
    
    PURPOSE OF THIS FILE: Driver file for the Convex Hull that used the Insertiom algorithm
    
    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/
#include "graham_slow.c"
#include<stdio.h>

int main()
{

    int i;
    long int size;
    stack S;
    Create(&S);

    importTxt(&S, &size);

    printf("\nBEFORE CONVEX: ");
    for (i = 0; i < size; i++)
    {
        printf("\n%d %lf %lf", i, S.coords[i].X, S.coords[i].Y);
    }

    printf("\n");

    cv(&size, &S);

    printf("\nCONVEX HULL: ");

    for (i = 0; i <= S.top; i++)
    {
        printf("\n%d %lf %lf", i, S.coords[i].X, S.coords[i].Y);
        //T.coords[i] = S.coords[i];
    }

    exportTxt(S, S.top);
}