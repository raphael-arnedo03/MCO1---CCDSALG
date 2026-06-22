/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04
    
    PURPOSE OF THIS FILE: To show an example of the sort.c program.

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
 		printf("%d %.4lf\t%.4lf\n", Coords[i].index, Coords[i].X, Coords[i].Y);
 	}
}

int main()
{	
	int nSize, i = 0;
	char fileInput[MAX];
	FILE *fp;
   	
   	printf("File name, no spaces: ");
   	scanf("%s", fileInput);
   	fp = fopen(fileInput, "r");
   	fscanf(fp, "%d", &nSize);
   	
   	Point Coords[nSize];
	
   	// Imports file into the struct array
   	for (i = 0; i < nSize; i++) {
 		fscanf(fp, "%lf %lf", &Coords[i].X, &Coords[i].Y);
 		Coords[i].index = i;
 	}
   	printf("\nImport Test");
   	printArray(Coords, nSize);
   	
   	// Testing if the anchor point is found
   	findAnchorPoint(Coords, nSize);
   	printf("\nAnchor Point Test");
   	printArray(Coords, nSize);
   	
   	// Using insertion sort on the current points
   	insertionSort(Coords, nSize);
   	printf("\nInsertion Sort Test");
   	printArray(Coords, nSize);
   	
   	// Using quick sort on the current points
   	quickSort(Coords, 1, nSize - 1);
   	printf("\nQuick Sort Test");
	printArray(Coords, nSize);
   	
   	fclose(fp);
	return 0;
}