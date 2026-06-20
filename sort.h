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
#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <math.h>

#define MAX 32768
#define PI 3.1415926535

struct coordinates{

    double X;
    double Y;
    int index;
};

typedef struct coordinates Point;

struct stackTemp{

    // STRICT REQUIREMENT #3

    Point coords[MAX];
    int top; // index of the array (has to be top always)
};

typedef struct stackTemp stack;

//#define PI 3.141592

void findAnchorPoint(Point Coords[], int nSize);
int compareDistance(Point Coords[], Point P1, Point P2);
int comparePolarAngles(Point Coords[], Point P1, Point P2);
void insertionSort(Point Coords[], int nSize);
int partition(Point Coords[], int low, int high);
void quickSort(Point Coords[], int low, int high);

#endif


