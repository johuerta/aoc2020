#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int rideSlope(char *path, int x, int y)
{

    FILE *fp;
    fp = fopen( path, "r" );
    
    // input is 32x323
    char line[33]; // fgets adds null termination
    int currentIndex = 0;
    int treeCounter = 0;
    int lineCounter = 0;
    while (fgets(line, LINE_MAX, fp) != NULL) 
    {
        if(lineCounter % y == 0)
        {
            if(line[currentIndex] == '#')
            {
                treeCounter++;
            }
            //printf("%s%*c %i %i %i\n", line, currentIndex+1, '^', currentIndex, treeCounter, lineCounter);
            currentIndex = (currentIndex + x) % 31;
        }
        lineCounter++;
    }
    
    printf("trees hit: %i\n", treeCounter);
    fclose(fp);
    return treeCounter;
}

int dayThreePart2(char *path)
{
    long long int totalTrees = 1;
    long long int a = rideSlope(path, 1,1);
    printf("Total trees hit: %lli\n",a);
    long long int b = rideSlope(path, 3,1);
    printf("Total trees hit: %lli\n",b);
    long long int c = rideSlope(path, 5,1);
    printf("Total trees hit: %lli\n",c);
    long long int d = rideSlope(path, 7,1);
    printf("Total trees hit: %lli\n",d);
    long long int e = rideSlope(path, 1,2);
    printf("Total trees hit: %lli\n",e);
    totalTrees = a * b * c * d * e;
    printf("Tree multiplication = %lli\n", totalTrees);
}

int dayThreePart1(char *path)
{

    FILE *fp;
    fp = fopen( path, "r" );

    // input is 32x323
    char line[33]; // fgets adds null termination
    int currentIndex = 0;
    int treeCounter = 0;
    int lineCounter = 1;
    while (fgets(line, LINE_MAX, fp) != NULL) 
    {
        if(line[currentIndex] == '#')
        {
            treeCounter++;
        }
        //printf("%s%*c %i %i %i\n", line, currentIndex+1, '^', currentIndex, treeCounter, lineCounter);
        currentIndex = (currentIndex + 3) % 31;
        lineCounter++;
    }
    
    printf("part 1 trees hit: %i\n", treeCounter);
    fclose(fp);
    return 0;
}

int main(int argc, char **argv)
{
    dayThreePart1(argv[1]);
    dayThreePart2(argv[1]);
    return 0;
}
