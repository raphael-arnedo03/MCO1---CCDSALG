/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04
    
    PURPOSE OF THIS FILE: Helper file for main and stacking functions. Has the importing and exporting functions.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/
#ifndef STACKHELPER_C
#define STACKHELPER_C

#include "stack.h"

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: A function helper for lowestPoint function that performs the distance formula
    e. Return: The answer to the two points being inserted in the distance formula.
    f. Parameters: Point a - First point
    		   Point b - Second point to compare to first point
*/
double distanceForm(Point a, Point b)
{
    return sqrt( ((a.X - b.X) * (a.X - b.X)) + ((a.Y - b.Y) * (a.Y - b.Y)));
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: to find the leftmost, lowest point in the convex hull
    		and to sort it using polar coordinates from the origin to determine
    		which point goes next (makes stack operations 67x easier)
    e. Return: None
    f. Parameters: Coords[] - set of all the coordinates
    		   Count - how many elements there are
*/
void lowestPoint(Point coords[], int count){

    int i, j = 0;
    Point tempCoords;

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
    
    Point lowest = coords[0];
    // insertion algo

    double tempDegrees, compareDegrees;
    for (i = 1; i < count; i++)
    {

        tempCoords = coords[i];
        j = i - 1;

        // tangent formula * radians conversion formula
        // subtract to the lowest point to relocate the center
        // or else it will perform angle calculations relative to the origin

        tempDegrees = atan2(tempCoords.Y - lowest.Y, tempCoords.X - lowest.X) * (180.0/PI);
        compareDegrees = atan2(coords[j].Y - lowest.Y, coords[j].X - lowest.X) * (180.0/PI);

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

}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: Determines if its cw, ccw, or collinear
    		uses the difference of 2 slopes found using 3 points
    e. Return: -1: cw turn
    		1: ccw turn
    		0: collinear
    f. Parameters: Point next - The next point
    		   Point top - The most top point
    		   Point secondTop - The second to the most top point
*/
int orientation(Point next, Point top, Point secondTop){

    double o = (next.Y - top.Y) * (top.X - secondTop.X) - (top.Y - secondTop.Y) * (next.X - top.X);

    // cw - continue
    // ccw - pop nextToTop

    if (o > 0) 
        return -1;
    else if (o < 0) 
        return 1;
    else return 0; 

}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: For importing Test-0.txt to Test-9.txt for testing with empirical time
    e. Return: none
    f. Parameters: stack *S - is the struct that will act as the stack
    		   int j - the test number for the filename
*/
void importTxtAuto(stack *S, int j)
{
    // used for empirical time
    FILE *fp;
    int i;
    int nSize;
    double tempX, tempY;
    char filename[20];

    sprintf(filename, "Test-%d.txt", j);
    fp = fopen(filename, "r");
    printf("%s\n", filename);
    
    fscanf(fp, "%d", &nSize);

    S->top = nSize - 1;

    i = 0;
    while(i < nSize)
    {
        fscanf(fp, "%lf", &tempX);
        fscanf(fp, "%lf", &tempY);

        S->coords[i].X = tempX;
        S->coords[i].Y = tempY;
        
        i++;
    }

    fclose(fp);
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: For importing txt files
    e. Return: none
    f. Parameters: stack *S - is the struct that will act as the stack
    		   long int *size - the size of the list
*/
void importTxt(stack *S, long int *size)
{
    FILE *fp;
    int i;
    char filename[MAX];

    printf("\nInput file name, no spaces: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    printf("%s\n", filename);
    
    int nSize;
    double tempX, tempY;
    fscanf(fp, "%d", &nSize);

    S->top = nSize - 1;

    i = 0;
    while(i < nSize)
    {
        fscanf(fp, "%lf", &tempX);
        fscanf(fp, "%lf", &tempY);

        S->coords[i].X = tempX;
        S->coords[i].Y = tempY;
        
        i++;
    }

    *size = nSize;

    fclose(fp);
}

/*
    a. Name of Programmer(s):  Arnedo, Raphael
    b. Name of Tester(s)    :  Joaquin Acierto
    c. Code Type -- 100% Human Generated 
    d. Purpose: Asks for a filename then exports the output into it
    e. Return: none
    f. Parameters: stack *S - is the struct that will act as the stack
    		   int j - the test number for the filename
*/
void exportTxt(stack S, long int size)
{

    FILE *fp;
    char fileOutput[MAX];
    printf("\nOutput file name: ");
    scanf("%s", fileOutput);

    fp = fopen(fileOutput, "w");

    fprintf(fp, "%ld\n", size+1);
    int i = 0;
    while (i <= size)
    {

        fprintf(fp, "%.5lf %.5lf\n", S.coords[i].X, S.coords[i].Y);
        i++;
    }
}

#endif