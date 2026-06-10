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

        S->coords[i].X = tempX;
        S->coords[i].Y = tempY;
        
        i++;
    }
}

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

Point Top(stack S){

    return S.coords[S.top];
}

Point nextToTop(stack S){

    if (S.top <= 0)
    {
        printf("Not enough elements!!\n");
    }

    return S.coords[S.top - 1];
}

bool stackEmpty(stack S){

    if (S.top >= -1 && S.top < 2)
        return true;
    else return false;
}

bool stackFull(stack S){

    if (S.top == 32767)
        return true;
    else return false;
}

// helper func for lowest pt refer below
double distanceForm(Point a, Point b)
{
    return sqrt( ((a.X - b.X) * (a.X - b.X)) + ((a.Y - b.Y) * (a.Y - b.Y)));
}

void lowestPoint(Point coords[], int count){

    // Purpose is to find the leftmost, lowest point in the convex hull
    // and to sort it using polar coordinates from the origin to determine
    // which point goes next (makes stack operations 67x easier)

    int i, j, k = 0;
    Point tempCoords;
    Point compareCoords;
    Point firstElem;

    // find the first element

    for (i = 1; i < count; i++)
    {

        tempCoords = coords[i];
        j = i - 1;

        while (j >= 0 && (coords[j].Y > tempCoords.Y
        || (coords[j].Y == tempCoords.Y && coords[j].X > tempCoords.X)))
        {
            coords[j+1] = coords[j];
            j--;
        }
        coords[j + 1] = tempCoords;
    }
    printf("count: %d\n\n", i);
    
    /*for (i = 0; i < count; i++)
    {
        printf("%lf %lf\n", coords[i].X, coords[i].Y);
    }*/

    Point lowest = coords[0];
    printf("lowest: %lf %lf\n", lowest.X, lowest.Y);
    // insertion algo

    double tempDegrees, compareDegrees;
    for (i = 1; i < count; i++)
    {

        tempCoords = coords[i];
        j = i - 1;

        // tangent formula * radians conversion formula
        // subtract to the lowest point to relocate the center
        // or else it will perform angle calculations relative to the origin

        tempDegrees = atan2(tempCoords.Y/*coords[i].Y*/ - lowest.Y, tempCoords.X/*coords[i].X*/ - lowest.X) * (180/PI);
        compareDegrees = atan2(coords[j].Y - lowest.Y, coords[j].X - lowest.X) * (180/PI);

        // fail safe to check if there are less than 3 elements in the array

        while (j >= 0)
        {
            compareDegrees = atan2(coords[j].Y - lowest.Y, coords[j].X - lowest.X) * (180/PI);
        
            // checks if j has a higher angle than i and if so puts it higher on the array
            // distanceForm is used here if ever the degrees of j and i are the same in which 
            // we get the one whos closer to the lowest point in terms of distance

            if ((compareDegrees > tempDegrees)
            || (compareDegrees == tempDegrees &&
                distanceForm(coords[j], lowest) > distanceForm(tempCoords, lowest))){

                coords[j+1] = coords[j];
                j--; 
            }
            else
                break;
        }

        coords[j + 1] = tempCoords;
    }

    for (i = 0; i < count; i++)
    {
        printf("ORDERED?: %lf %lf\n", coords[i].X, coords[i].Y);
    }

    /*for (i = 1; i < count + 1; i++)
    {
        j = i - 1;
        tempCoords = coords[i];

        while (j >= 0 && (coords[j].Y > tempCoords.Y)){


            coords[j+1] = coords[j];
            j--; 
        }

        coords[j + 1] = tempCoords;
    }*/
}

int orientation(Point next, Point top, Point secondTop){

    // determines if its cw, ccw, or collinear
    // uses the difference of 2 slopes found using 3 points
    // here it is derived in this format
    double o = (next.Y - top.Y) * (top.X - secondTop.X) - (top.Y - secondTop.Y) * (next.X - top.X);

    // cw - continue
    // ccw - pop nextToTop

    if (o > 0) // cw turn
        return -1;
    else if (o < 0) // ccw turn
        return 1;
    else return 0; // collinear

}

void convexHull(stack S){

    if (!stackEmpty(S))
    {
        int i = 0;
        int ceiling = S.top + 1;
        //lowestPoint(S.coords, S.top);

        //printf("\nceiling; %d", ceiling);

        //printf("\nTop: %lf %lf", Top(S).X, Top(S).Y);
        //printf("\nNext to Top: %lf %lf", nextToTop(S).X, nextToTop(S).Y);

        //printf("\n\n");

        lowestPoint(S.coords, ceiling);

        S.top = 1;
        i = 2;

        while (i < ceiling)
        {

            // you can implement a function to flip the order so that the lowest leftmost pt
            // can be at the top of the stack but its gonna make ts 100000x slower so idk

            Point top = Top(S);
            //printf("TOP: %lf %lf\n", top.X, top.Y);
            Point secondTop = nextToTop(S);
            //printf("SECONDTOP: %lf %lf\n", secondTop.X, secondTop.Y);
            Point next = S.coords[i];
            //printf("NEXT: %lf %lf\n", next.X, next.Y);

            if (orientation(next, top, secondTop) < 0)
            {
                i++;
                Push(&S, next);
            }
            else
            {
                printf("Popped\n");
                Pop(&S);
            }
        }

        for (i=0; i <= S.top; i++)
        {
            printf("\n%lf %lf", S.coords[i].X, S.coords[i].Y);
        }

        printf("\n%d", i);

    }
}

