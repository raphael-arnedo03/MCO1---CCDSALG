/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04
    
    PURPOSE OF THIS FILE: To show an example of the stack.c program working.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/

#include <stdlib.h>

// include your own stack C source file
#include "stack.c"

int main()
{
   stack S;
   Create(&S);

	
   FILE *fp;
   char fileInput[MAX];
   printf("File name, no spaces: ");
   scanf("%s", fileInput);
   fp = fopen(fileInput, "r");
	
	// Creates the empty stack
   printf("\nSTACK EMPTY: %d\n", stackEmpty(&S));
	
	// Shows the stack before the operations
   printf("\nBEFORE STACK OPS: ");

   int i = 0;
   int nSize;
	
	// Imports the file and sets the data into the stack and sets the size of the elements
   fscanf(fp, "%d", &nSize);
   while (i < nSize)
   {
        fscanf(fp, "%lf %lf", &S.coords[i].X, &S.coords[i].Y);
        printf("\n%d %lf %lf", i , S.coords[i].X, S.coords[i].Y);
        i++;
   }
   printf("\n");

   S.top = nSize - 1;

   printf("\nTOP: %lf %lf", Top(&S).X, Top(&S).Y);
   printf("\nSECOND TOP: %lf %lf", nextToTop(&S).X, nextToTop(&S).Y);
   printf("\nPUSH POINT (5,5)");

   Point FiveFive;
   FiveFive.X = 5;
   FiveFive.Y = 5;
   Push(&S, FiveFive);

   printf("\nTOP: %lf %lf", Top(&S).X, Top(&S).Y);
   printf("\nSECOND TOP: %lf %lf", nextToTop(&S).X, nextToTop(&S).Y);

   printf("\nPOP TWICE:");
   Pop(&S);
   Pop(&S);

   printf("\nTOP: %lf %lf", Top(&S).X, Top(&S).Y);
   printf("\nSECOND TOP: %lf %lf\n", nextToTop(&S).X, nextToTop(&S).Y);
	
	// Prints the full check for the stack
   printf("\nSTACK FULL: %d", stackFull(&S));

}


