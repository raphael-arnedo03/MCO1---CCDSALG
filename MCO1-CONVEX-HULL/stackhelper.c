#ifndef STACKHELPER_C
#define STACKHELPER_C

#include "stack.h"

// helper func for lowest pt refer below
double distanceForm(Point a, Point b)
{
    return sqrt( ((a.X - b.X) * (a.X - b.X)) + ((a.Y - b.Y) * (a.Y - b.Y)));
}

void lowestPoint(Point coords[], int count){

    // Purpose is to find the leftmost, lowest point in the convex hull
    // and to sort it using polar coordinates from the origin to determine
    // which point goes next (makes stack operations 67x easier)

    int i, j, k = 0;
    Point tempCoords;
    Point compareCoords;
    Point firstElem;

    // find the first element

    for (i = 1; i < count; i++)
    {

        tempCoords = coords[i];
        j = i - 1;

        while (j >= 0 && (coords[j].Y > tempCoords.Y
        || (coords[j].Y == tempCoords.Y && coords[j].X > tempCoords.X)))
        {
            coords[j+1] = coords[j];
            j--;
        }
        coords[j + 1] = tempCoords;
    }
    //printf("count: %d\n\n", i);
    
    /*for (i = 0; i < count; i++)
    {
        printf("%lf %lf\n", coords[i].X, coords[i].Y);
    }*/

    
    Point lowest = coords[0];
    // insertion algo

    double tempDegrees, compareDegrees;
    for (i = 1; i < count; i++)
    {

        tempCoords = coords[i];
        j = i - 1;

        // tangent formula * radians conversion formula
        // subtract to the lowest point to relocate the center
        // or else it will perform angle calculations relative to the origin

        tempDegrees = atan2(tempCoords.Y/*coords[i].Y*/ - lowest.Y, tempCoords.X/*coords[i].X*/ - lowest.X) * (180/PI);
        compareDegrees = atan2(coords[j].Y - lowest.Y, coords[j].X - lowest.X) * (180/PI);

        // fail safe to check if there are less than 3 elements in the array

        while (j >= 0)
        {
            compareDegrees = atan2(coords[j].Y - lowest.Y, coords[j].X - lowest.X) * (180/PI);
        
            // checks if j has a higher angle than i and if so puts it higher on the array
            // distanceForm is used here if ever the degrees of j and i are the same in which 
            // we get the one whos closer to the lowest point in terms of distance

            if ((compareDegrees > tempDegrees)
            || (compareDegrees == tempDegrees &&
                distanceForm(coords[j], lowest) > distanceForm(tempCoords, lowest))){

                coords[j+1] = coords[j];
                j--; 
            }
            else
                break;
        }

        coords[j + 1] = tempCoords;
    }

    /*
    for (i = 0; i < count; i++)
    {
        printf("ORDERED?: %lf %lf\n", coords[i].X, coords[i].Y);
    }*/

    /*for (i = 1; i < count + 1; i++)
    {
        j = i - 1;
        tempCoords = coords[i];

        while (j >= 0 && (coords[j].Y > tempCoords.Y)){


            coords[j+1] = coords[j];
            j--; 
        }

        coords[j + 1] = tempCoords;
    }*/
}

int orientation(Point next, Point top, Point secondTop){

    // determines if its cw, ccw, or collinear
    // uses the difference of 2 slopes found using 3 points
    // here it is derived in this format
    double o = (next.Y - top.Y) * (top.X - secondTop.X) - (top.Y - secondTop.Y) * (next.X - top.X);

    // cw - continue
    // ccw - pop nextToTop

    if (o > 0) // cw turn
        return -1;
    else if (o < 0) // ccw turn
        return 1;
    else return 0; // collinear

}
/*
void convexHull(stack S){

    printf("aposdkjand");
    printf("%d\n", stackEmpty(S));
    if (!stackEmpty(&S))
    {
        int i = 0;
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
                printf("Popped\n");
                Pop(&S);
            }
        }

        for (i=0; i <= S.top; i++)
        {
            printf("\n%lf %lf", S.coords[i].X, S.coords[i].Y);
        }

        printf("\n%d", i);

    }
}*/

void importTxtAuto(stack *S, int j)
{ // for test 0 to 9 which is j
    // used for empirical time
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

    fclose(fp);
}

void importTxt(stack *S, long int *size)
{
    FILE *fp;
    int i;
    char filename[MAX];// = "input-circle.txt";

    printf("\nInput file name, no spaces: ");
    scanf("%s", filename);
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

void exportTxt(stack S, long int size)
{

    FILE *fp;
    char fileOutput[MAX];
    printf("\nOutput file name: ");
    scanf("%s", fileOutput);

    fp = fopen(fileOutput, "w");

    fprintf(fp, "%ld\n", size+1);
    int i = 0;
    while (i <= size)
    {

        fprintf(fp, "%.5lf %.5lf\n", S.coords[i].X, S.coords[i].Y);
        i++;
    }
}

#endif