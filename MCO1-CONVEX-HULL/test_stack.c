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

#include <stdlib.h>

// include your own stack C source file
#include "stack.c"

int main()
{
   // test the stack operations by calling the stack function.

   /*int x = 123; // document the purpose of the local variable(s)

   Sample(x);  // replace this line of code with your own set of codes

   return 0;*/

   // !!! ASK THE USER FOR FILE NAME AND USE CREATE STACK TO REINITIALIZE !!! //

   stack S;
   Create(&S);

   FILE *fp;
   char fileInput[MAX];
   printf("File name, no spaces: ");
   scanf("%s", fileInput);
   fp = fopen(fileInput, "r");

   printf("\nSTACK EMPTY: %d", stackEmpty(S));

   printf("\nBEFORE STACK OPS: ");

   int i = 0;
   int size;

   fscanf(fp, "%d", &size);

   while (i < size)
   {
        fscanf(fp, "%lf %lf", &S.coords[i].X, &S.coords[i].Y);
        printf("\n%d %lf %lf", i , S.coords[i].X, S.coords[i].Y);
        i++;
   }

   S.top = size - 1;

   printf("\nTOP: %lf %lf", Top(S).X, Top(S).Y);
   printf("\nSECOND TOP: %lf %lf", nextToTop(S).X, nextToTop(S).Y);
   printf("\nPUSH POINT (5,5)");

   Point FiveFive;
   FiveFive.X = 5;
   FiveFive.Y = 5;
   Push(&S, FiveFive);

   printf("\nTOP: %lf %lf", Top(S).X, Top(S).Y);
   printf("\nSECOND TOP: %lf %lf", nextToTop(S).X, nextToTop(S).Y);

   printf("\nPOP TWICE:");
   Pop(&S);
   Pop(&S);

   printf("\nTOP: %lf %lf", Top(S).X, Top(S).Y);
   printf("\nSECOND TOP: %lf %lf", nextToTop(S).X, nextToTop(S).Y);

   printf("\nSTACK FULL: %d", stackFull(S));

}


