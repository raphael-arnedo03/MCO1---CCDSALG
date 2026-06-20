/**

    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00  (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an eXample of a C source file that follows the coding guidelines/instructions.

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

void findAnchorPoint(Point Coords[], int nSize)
{
	int i, j;
	int anchorIndex;
	Point finder[nSize];
	Point temp;
	
	for(i = 0; i < nSize; i++) {
		finder[i] = Coords[i];
	}
	
	for (i = 0; i < nSize; i++) {
		for(j = i + 1; j < nSize; j++) {
			if(finder[i].Y > finder[j].Y){
				temp = finder[j];
				finder[j] = finder[i];
				finder[i] = temp;
			} else if (finder[i].Y == finder[j].Y) {
				if(finder[i].X > finder[j].X){
					temp = finder[j];
					finder[j] = finder[i];
					finder[i] = temp;
				} 
			}
		}
	}
	anchorIndex = finder[0].index; 
	
	Coords[anchorIndex] = Coords[0];
	Coords[0] = finder[0];
}

int compareDistance(Point Coords[], Point P1, Point P2){
	double fDistance1;
	double fDistance2;
	
	fDistance1 = (P1.X - Coords[0].X) * (P1.X - Coords[0].X) + (P1.Y - Coords[0].Y) * (P1.Y - Coords[0].Y);
	fDistance2 = (P2.X - Coords[0].X) * (P2.X - Coords[0].X) + (P2.Y - Coords[0].Y) * (P2.Y - Coords[0].Y);
	
	if(fDistance1 > fDistance2)
		return 1;
	else if(fDistance1 < fDistance2)
		return -1;
	else
		return 0;
}

int comparePolarAngles(Point Coords[], Point P1, Point P2){
	double fAngle1;
	double fAngle2;
	
	
	fAngle1 = atan2((P1.Y - Coords[0].Y),(P1.X - Coords[0].X)) * (180.0/PI);
	fAngle2 = atan2((P2.Y - Coords[0].Y),(P2.X - Coords[0].X)) * (180.0/PI);
	
	if(fAngle1 > fAngle2)
		return 1;
	else if(fAngle1 < fAngle2)
		return -1;
	else
		return compareDistance(Coords,P1,P2);
}

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

void quickSort(Point Coords[], int low, int high){
	if (low < high) {
        int ri = partition(Coords, low, high);

        quickSort(Coords, low, ri - 1);
        quickSort(Coords, ri + 1, high);
    }
}
