/*

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00 (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an example of a C header file that follows the coding guidelines/instructions.

    >> GENERAL INSTRUCTIONS:
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    3. Do NOT use global variables!  NON-COMPLIANCE WILL RESULT INTO A 10 POINT DEDUCTION!
*/

/*
    You may encode any of the following below this comment the following:   
    1. #define directives
    2. typedef alias(es) 
    3. declaration of your user-defined struct data type(s)
    4. typedef alias(es) for your struct data type(s) -- you have to put an inline comment 
       for each struct member as part of the documentation. 

    The header should NOT include the codes for any function definitions.  

    Function definitions should be encoded in your C source file only!
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "sort.h"

// you may include other header files

// example FUNCTION PROTOTYPE -- remove this and the next line in your own codes
void Sample(int x);

// helper function

void importTxtAuto(stack *S, int j);
void importTxt(stack *S, long int *size);
void exportTxt(stack S, long int size);

int orientation(Point next, Point top, Point secondTop); // return -1, 1 or 0 if its ccw, cw or collinear
void convexHull(stack S);
void lowestPoint(Point coords[], int count);
void lowestPoint(Point coords[], int count);

// function prototypes

void Create(stack *S);
void Push(stack *S, Point x);
void Pop(stack *S);
Point Top(stack *S);
Point nextToTop(stack *S);
bool stackEmpty(stack *S);
bool stackFull(stack *S);

#endif


  
