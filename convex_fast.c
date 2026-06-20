#include "sort.c"
//#include "sort.h"
#include "stack.c"
//#include "stack.h"
#include "stackhelper.c"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void importTxt(stack *S, int *size, int j)
{
    FILE *fp;
    int i;
    char filename[20];// = "input-circle.txt";

    sprintf(filename, "Test-%d.txt", j);
    fp = fopen(filename, "r");
    printf("%s\n", filename);
    
    //fp = fopen("sample-input.txt","r");
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

void cv(long int *N)
{
    int j;

    for (j = 9; j == 9; j++) // change cond to nth test number
    {
        //printf("ok");
        int size, i;
        stack S;
        Create(&S);

        importTxt(&S, &size, j);
        quickSort(S.coords, 1, size - 1);

        *N = size;

        if (!stackEmpty(S))
        {
            i = 0;
            int ceiling = S.top + 1;
            //lowestPoint(S.coords, S.top);

            //printf("\nceiling; %d", ceiling);

            //printf("\nTop: %lf %lf", Top(S).X, Top(S).Y);
            //printf("\nNext to Top: %lf %lf", nextToTop(S).X, nextToTop(S).Y);

            //printf("\n\n");

            lowestPoint(S.coords, ceiling);

            S.top = 1;
            i = 2;

            while (i < ceiling)
            {

                // you can implement a function to flip the order so that the lowest leftmost pt
                // can be at the top of the stack but its gonna make ts 100000x slower so idk

                Point top = Top(S);
                Point secondTop;
                //printf("TOP: %lf %lf\n", top.X, top.Y);

                if (S.top > 0)
                    secondTop = nextToTop(S);
                else
                    secondTop = top;
                    
                //printf("SECONDTOP: %lf %lf\n", secondTop.X, secondTop.Y);
                Point next = S.coords[i];
                //printf("NEXT: %lf %lf\n", next.X, next.Y);

                if (S.top == 0 || orientation(next, top, secondTop) < 0)
                {
                    i++;
                    Push(&S, next);
                }
                else
                {
                    //printf("Popped\n");
                    Pop(&S);
                }
            }

            /*for (i=0; i <= S.top; i++)
            {
                printf("\n%lf %lf", S.coords[i].X, S.coords[i].Y);
            }

            printf("\n%d", i);*/

        }
    }
}