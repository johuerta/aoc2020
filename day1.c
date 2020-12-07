
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SIZE 200
 
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{

        int index = 0;
        int numbers [SIZE];
        int opposites [SIZE];
        int sums [SIZE][SIZE];
        int sumsOpposites [SIZE][SIZE];
                
        for(index = 0; index < SIZE; index++)
        {
            scanf("%i", &numbers[index]);  
            opposites[index] = 2020 - numbers[index];
        }

        qsort(numbers,SIZE,sizeof(int), cmpfunc);
        qsort(opposites,SIZE,sizeof(int),cmpfunc);

        /*
        for(index = 0; index < SIZE; index++)
        {
            for(int j = 0; j < SIZE; j++)
            { 
                sums[index][j] = numbers[index] + numbers[j];
                sumsOpposites[index][j] = 2020 - sums[index][j];
            }
        }
        */
        for(index = 0; index < SIZE; index++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                sums[index][j] = numbers[index] + numbers[j];
                sumsOpposites[index][j] = 2020 - sums[index][j];
                for(int k = 0; k < SIZE; k++)
                {
                    if(sumsOpposites[index][j] == numbers[k])
                    {
                        printf("%i * %i * %i : %i\n", numbers[k], numbers[index], numbers[j],
                               numbers[k] * numbers[index] * numbers[j]);                    
                        printf("%i %i %i", k, index, j);
                        return 0;
                    }
                }
            }
        }
        return 0;
}
