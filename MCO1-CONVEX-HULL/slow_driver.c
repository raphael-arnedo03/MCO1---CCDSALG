#include "convex_slow.c"
#include<stdio.h>

int main()
{

    int i;
    long int size;
    stack S;
    //stack T;
    Create(&S);
    //Create(&T);

    importTxt(&S, &size);

    printf("\nBEFORE CONVEX: ");
    for (i = 0; i < size; i++)
    {
        printf("\n%d %lf %lf", i, S.coords[i].X, S.coords[i].Y);
    }

    printf("\n");

    cv(&size, &S);

    printf("\nCONVEX HULL: ");

    for (i = 0; i <= S.top; i++)
    {
        printf("\n%d %lf %lf", i, S.coords[i].X, S.coords[i].Y);
        //T.coords[i] = S.coords[i];
    }

    exportTxt(S, S.top);
}