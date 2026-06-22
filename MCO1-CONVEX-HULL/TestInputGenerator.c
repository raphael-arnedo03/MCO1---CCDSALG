/**
    >> Encode your group number (2 digits) and last names, first names and sections of group members.  Encode the purpose of this file.

    Group #: 10  (2 digits)

    ARNEDO, RAFAEL S09
    ACIERTO, JOAQUIN S04
    
    PURPOSE OF THIS FILE: Creates 10 test case files with randomized elements.

    >> GENERAL INSTRUCTIONS: NON-COMPLIANCE WILL RESULT INTO AT LEAST A 10 POINT DEDUCTION!
    1. Adhere with good programming style and practice (learned from CCPROG1 and CCPROG2).
    2. Do NOT use global variables!  
    3. Do NOT use goto statement!
    4. Do NOT use return in a void function!
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef char String25[25]; 

/*
    a. Name of Programmer(s):  Joaquin Acierto
    b. Name of Tester(s)    :  Raphael Arnedo
    c. Code Type -- 100% Human Generated 
    d. Purpose: Creates a random double number from a range
    e. Return: A random double number
    f. Parameters: Point Coords[] is the set of all coordinates.
    		   low is the minimum index to search through in the array
    		   high is the maximum index to search through in the array
*/
double randfrom(double min, double max) 
{
    double dRange = (max - min); 
    double dDiv = RAND_MAX / dRange;
    return min + (rand() / dDiv);
}

int main(){
	int i;
	int n = 6; // Starts the first test file with 2^6 which is 64 elements
	int nTest = 0; 
	srand(time(NULL)); 
	int nLimit; // How many elements to print based on 2^n
	FILE *fp;
	String25 sFileName = "Test-0.txt";
	
	do {
		sFileName[5] = '0' + nTest;
		fp = fopen(sFileName, "w");
		
		nLimit = pow(2,n);
		fprintf(fp,"%d\n", nLimit);
		for(i = 0; i < nLimit; i++)
			fprintf(fp,"%11.6lf%12.6lf\n", randfrom(-5.0,5.0), randfrom(-5.0,5.0));
		n++;	
		nTest++;
		fclose(fp);
	} while (nTest < 10);

	return 0;
}