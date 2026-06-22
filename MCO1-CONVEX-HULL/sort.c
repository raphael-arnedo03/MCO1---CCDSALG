/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04

    PURPOSE OF THIS FILE: Holds the programs for the sorting algorithms

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!

*/

#include <stdio.h>
#include <math.h>

// include your own stack header file
#include "sort.h"


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

// Sort Operations

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Finds the anchor point within the coordinates, which is the lowest minimum y and x point 
    		and puts it on the first index of the array
    e. Return: none
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   nSize is the the amount of elements there are in the set.
*/
void findAnchorPoint(Point Coords[], int nSize)
{

    int i, j;
    Point tempCoords;

    for (i = 1; i < nSize; i++)
    {

        tempCoords = Coords[i];
        j = i - 1;

        while (j >= 0 && (Coords[j].Y > tempCoords.Y
        || (Coords[j].Y == tempCoords.Y && Coords[j].X > tempCoords.X)))
        {
            Coords[j+1] = Coords[j];
            j--;
        }
        Coords[j + 1] = tempCoords;
    }
}

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Uses distance formula from a set point to the anchor point with two different points
    		and compares which distance is greater
    e. Return: 1 if the 1st Distance is greater than the 2nd Distance
    	 	2 if the 1st Distance is lesser than the 2nd Distance
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   P1 is the 1st Point
    		   P2 is the 2nd Point to compare to P1
*/
int compareDistance(Point Coords[], Point P1, Point P2){
	double fDistance1;
	double fDistance2;
	
	//Distance formula
	fDistance1 = (P1.X - Coords[0].X) * (P1.X - Coords[0].X) + (P1.Y - Coords[0].Y) * (P1.Y - Coords[0].Y);
	fDistance2 = (P2.X - Coords[0].X) * (P2.X - Coords[0].X) + (P2.Y - Coords[0].Y) * (P2.Y - Coords[0].Y);
	
	if(fDistance1 > fDistance2)
		return 1;
	else if(fDistance1 < fDistance2)
		return -1;
	else
		return 0;
}

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Converts 2 points from the anchor point to angles then compares the angless with each
    		other. If the angles are the same, use Distance formula to see which is nearer.
    e. Return: 1 if the 1st Distance is greater than the 2nd Distance
    	 	2 if the 1st Distance is lesser than the 2nd Distance
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   P1 is the 1st Point
    		   P2 is the 2nd Point to compare to P1
*/
int comparePolarAngles(Point Coords[], Point P1, Point P2){
	double fAngle1;
	double fAngle2;
	
	// rise/run formula, then arctan(rise/run) to convert points to angles
	fAngle1 = atan2((P1.Y - Coords[0].Y),(P1.X - Coords[0].X));
	fAngle2 = atan2((P2.Y - Coords[0].Y),(P2.X - Coords[0].X));
	
	if(fAngle1 > fAngle2)
		return 1;
	else if(fAngle1 < fAngle2)
		return -1;
	else
		return compareDistance(Coords,P1,P2);
}

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Uses insertionSort to sort the coordinates counter-clockwise from the anchor point
    e. Return: none
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   nSize is the count of elements.
*/
void insertionSort(Point Coords[], int nSize){
	int i, j;
	Point Key;
	
	for(i = 2; i < nSize; i++){
	        Key = Coords[i];
	        
	        j = i - 1;
	        while (j >= 1 && comparePolarAngles(Coords,Coords[j], Key) > 0) {
	            Coords[j + 1] = Coords[j];
	            j--;
	        }
	        
	        Coords[j + 1] = Key;
    	}
}

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Is the main sorting function of quicksort. Searching through the mininum and maximum index
    		then decreasing the minimum and maximum index until it reaches its goal.
    e. Return: i which is added to minimum and subtracted from the maxmimum
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   low is the minimum index to search through in the array
    		   high is the maximum index to search through in the array
*/
int partition(Point Coords[], int low, int high) {
	Point Pivot;
	Point Temp; 
	int i, j;
	
	Pivot = Coords[high];
	i = (low - 1); 
	
	for (j = low; j < high; j++) {
		if (comparePolarAngles(Coords,Coords[j],Pivot) == -1){
		        i++; 
		        Temp = Coords[i];
		    	Coords[i] = Coords[j];
		    	Coords[j] = Temp;
		}
	}
	
	Temp = Coords[i + 1];
    	Coords[i + 1] = Coords[high];
    	Coords[high] = Temp;
    		
	return (i + 1);
}

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Uses quickSort to sort the coordinates counter-clockwise from the anchor point.
    		Uses recursion to achieve this.
    e. Return: none
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   low is the minimum index to search through in the array
    		   high is the maximum index to search through in the array
*/
void quickSort(Point Coords[], int low, int high){
	if (low < high) {
        int ri = partition(Coords, low, high);

        quickSort(Coords, low, ri - 1);
        quickSort(Coords, ri + 1, high);
    }
}
