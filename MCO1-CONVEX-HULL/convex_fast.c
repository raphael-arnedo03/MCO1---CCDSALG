#include "sort.c"
//#include "sort.h"
#include "stack.c"
//#include "stack.h"
#include "stackhelper.c"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void cv(long int *N, stack *S)
{
    int j = 9; // 9th j is the one with 2^15 elems

    int size, i;
    size = S->top + 1;
    //stack S;
    //Create(&S);

    //importTxtAuto(&S, &size, j);
    quickSort(S->coords, 1, size - 1);

    *N = size;

    printf("%d", stackEmpty(&*S));

    if (!stackEmpty(&*S))
    {
        i = 0;
        int ceiling = S->top + 1;
        //lowestPoint(S.coords, S.top);

        //printf("\nceiling; %d", ceiling);

        //printf("\nTop: %lf %lf", Top(S).X, Top(S).Y);
        //printf("\nNext to Top: %lf %lf", nextToTop(S).X, nextToTop(S).Y);

        //printf("\n\n");

        lowestPoint(S->coords, ceiling);

        S->top = 1;
        i = 2;

        while (i < ceiling)
        {

            // you can implement a function to flip the order so that the lowest leftmost pt
            // can be at the top of the stack but its gonna make ts 100000x slower so idk

            Point top = Top(&*S);
            Point secondTop;
            //printf("TOP: %lf %lf\n", top.X, top.Y);

            if (S->top > 0)
                secondTop = nextToTop(&*S);
            else
                secondTop = top;
                
            //printf("SECONDTOP: %lf %lf\n", secondTop.X, secondTop.Y);
            Point next = S->coords[i];
            //printf("NEXT: %lf %lf\n", next.X, next.Y);

            if (S->top == 0 || orientation(next, top, secondTop) < 0)
            {
                i++;
                Push(&*S, next);
            }
            else
            {
                //printf("Popped\n");
                Pop(&*S);
            }
        }

        /* printing out the convex hull
        for (i=0; i <= S.top; i++)
        {
            printf("\n%lf %lf", S.coords[i].X, S.coords[i].Y);
        }

        printf("\n%d", i);*/

    }
}