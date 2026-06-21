/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00  (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an example of a C source file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// include your own stack header file
#include "stack.h"


/*
    EACH FUNCTION DEFINITION MUST BE PRECEDED BY A INLINE DOCUMENTATION CONTAINING THE FOLLOWING:

    a. Name of Programmer(s)
    b. Name of Tester(s) -- for an unbiased black box testing, the tester should NOT be the same person as the programmer.
    c. Code Type -- indicate EXPLICITLY if the code is one of the following: 100% Human Generated code, 100% AI Generated code
       or a modified AI generated code.  If it is a modified AI generated code, indicate explicitly which lines were 
       modified and the reason why a line of code had to be modified.
    d. Purpose -- indicate the purpose of the function
    e. Return -- indicate what will be returned (type None for void functions)
    f. Parameters -- indicate the nature of the parameters

    An example is shown below.  

    Remove the Sample() function in your own C source code.
*/


/*
    a. Name of Programmer(s):  Juan de la Cruz, Anna Santos
    b. Name of Tester(s)    :  Ichiro Makino
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will ....
    e. Return: None
    f. Parameters: x is the ...    
*/
void Sample(int x)
{
    // document also the body of the function
    printf("Hello %d.\n", x);
}

// Helper Functions
/*
void importTxt(FILE *fp, stack *S){

    int nSize;
    double tempX, tempY;
    fscanf(fp, "%d", &nSize);

    S->top = nSize - 1;

    int i = 0;
    while(i < nSize)
    {
        fscanf(fp, "%lf", &tempX);
        fscanf(fp, "%lf", &tempY);

        printf("tempX: %lf, tempY: %lf\n", tempX, tempY);
        S->coords[i].X = tempX;
        S->coords[i].Y = tempY;
        
        i++;
    }
}*/

// Stack Operations

void Create(stack *S){

    S->top = -1; // empty stack
}

void Push(stack *S, Point x){

    if (S->top < 32767)
    {
        S->top++;
        S->coords[S->top] = x;
    }
    else
        printf("Stack overflow!\n");
}

void Pop(stack *S){

    if (S->top > -1)
    {
        S->top--; // decrements the top index so if u push the actual leading index gets replaced
    }
    else
        printf("Stack underflow!\n");
}

Point Top(stack *S){

    return S->coords[S->top];
}

Point nextToTop(stack *S){

    if (S->top <= 0)
    {
        printf("Not enough elements!!\n");
    }

    return S->coords[S->top - 1];
}

bool stackEmpty(stack *S){

    if (S->top >= -1 && S->top < 2)
        return true;
    else return false;
}

bool stackFull(stack *S){

    if (S->top == 32767)
        return true;
    else return false;
}

