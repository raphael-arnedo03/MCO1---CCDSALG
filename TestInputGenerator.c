#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef char String25[25]; 

double randfrom(double min, double max) 
{
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int main(){
	int i;
	int n = 6;
	int nTest = 0;
	srand(time(NULL)); 
	//int randomN = (rand() % (14 - 6 + 1)) + 6;
	int nLimit;
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

	/*
	nLimit = 15;
	fp = fopen(sFileName, "w");
	for(i = 0; i < nLimit; i++)
			fprintf(fp,"%11.6lf%12.6lf\n", randfrom(-5.0,5.0), randfrom(-5.0,5.0));
	fclose(fp);*/

	return 0;
}