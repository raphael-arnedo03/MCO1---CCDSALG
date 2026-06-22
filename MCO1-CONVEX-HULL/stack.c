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

// Stack Operations

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will create a new stack
    e. Return: None
    f. Parameters: stack *S - is the struct that will act as the stack
*/
void Create(stack *S){

    S->top = -1; // empty stack
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function pushes a new element into the stack
    e. Return: None
    f. Parameters: stack *S - is the struct that will act as the stack
*/
void Push(stack *S, Point x){

    if (S->top < 32767)
    {
        S->top++;
        S->coords[S->top] = x;
    }
    else
        printf("\nStack overflow!");
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function will remove the top element from the stack
    e. Return: None
    f. Parameters: stack *S - is the struct that will act as the stack
*/
void Pop(stack *S){

    if (S->top > -1)
    {
        S->top--; // decrements the top index so if u push the actual leading index gets replaced
    }
    else
        printf("\nStack underflow!");
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: This function calls the top element from the stack
    e. Return: The top element in the stack
    f. Parameters: stack *S - is the struct that will act as the stack
*/
Point Top(stack *S){

    return S->coords[S->top];
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: this function call the element next to the top from the stack
    e. Return: The element nearest to the top in the stack
    f. Parameters: stack *S - is the struct that will act as the stack
*/
Point nextToTop(stack *S){

    if (S->top <= 0)
    {
        printf("\nNot enough elements!!");
    }

    return S->coords[S->top - 1];
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: Checks if the stack is empty or not
    e. Return: True if the stack is empty and False if the stack is not
    f. Parameters: stack *S - is the struct that will act as the stack
*/
bool stackEmpty(stack *S){

    if (S->top >= -1 && S->top < 2)
        return true;
    else return false;
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: Checks if the stack is full or not
    e. Return: True if the stack is full and False if the stack is not
    f. Parameters: stack *S - is the struct that will act as the stack
*/
bool stackFull(stack *S){

    if (S->top == 32767)
        return true;
    else return false;
}

