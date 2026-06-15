/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 00  (2 digits)

    LASTNAME1, FIRSTNAME1  SECTION
    LASTNAME2, FIRSTNAME2  SECTION
    LASTNAME3, FIRSTNAME3  SECTION 

    PURPOSE OF THIS FILE: to show an example of a test driver program.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/
#include <stdio.h>
#include <stdlib.h>

// include your own sort C source file
#include "sort.c"

//For Testing
void printArray(Point Coords[], int nSize){
	int i;
	
	printf ("\nSize: %d\n", nSize);
	printf ("# X\t\tY\n");
	for (i = 0; i < nSize; i++) {
 		printf("%d %.4lf\t%.4lf\n", Coords[i].index, Coords[i].x, Coords[i].y);
 	}
}

int main()
{
	int nSize;
	FILE *fp;
	
   	fp = fopen("input-circle.txt", "r");
   	fscanf(fp, "%d", &nSize);
   	
   	Point Coords[nSize];
   	importTxt(Coords, nSize, fp);
   	printf("\nImport Test");
   	printArray(Coords, nSize);
   	
   	findAnchorPoint(Coords, nSize);
   	printf("\nAnchor Point Test");
   	printArray(Coords, nSize);
   	
   	insertionSort(Coords, nSize);
   	printf("\nInsertion Sort Test");
   	printArray(Coords, nSize);
   	
   	quickSort(Coords, 1, nSize - 1);
   	printf("\nQuick Sort Test");
	printArray(Coords, nSize);
   	
   	fclose(fp);
	return 0;
}
