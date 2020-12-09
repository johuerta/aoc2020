#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int isValid(long long int numbers[], int start, int end)
{
	for(int i = start; i < end; i++)
	{
		for(int j = start; j < end; j++)
		{
			if(i == j) continue;
			if(numbers[i] + numbers[j] == numbers[end])
				return 1;
		}
	}
	return 0;	
}

int findWeakness(long long int numbers[], int start, int end)
{
	int n_numbers = end-start+1;
	long long int numbers_copy [n_numbers];
	memcpy(numbers_copy, numbers+start, sizeof(long long int) * (n_numbers));
	qsort(numbers_copy, n_numbers, sizeof(long long int), cmpfunc);
   	return numbers_copy[0] + numbers_copy[n_numbers-1];	
}

long long int part2(long long int numbers[], int start, long long int sum)
{
	long long int acc;
	
	for(int i = start; i >= 0; i--)
	{
		int j;
		acc = sum;
		j = i;
		while(acc > 0)
		{
			acc -= numbers[j];
			j--;
		}

		if(acc == 0)
		{
			// find the smallest and largest number
			return findWeakness(numbers, j+1, i); 
		}
		
	}	
	return 0;
}

int main(int argc, char **argv)
{
	long long int numbers[1000];
	int start = 0, index = 0;

	// preamble
	for(index = 0; index < 25; index++)
	{
		scanf("%lld", &numbers[index]);
	}

	while(scanf("%lld", &numbers[index]) > 0)
	{
		// is numbers[index] valid?
		if(isValid(numbers, start, index) == 0)
		{
			printf("part1: %i, %i - %lld\n", start, index, numbers[index]);
			break;
		}
		start++;
		index++;
	}

	printf("part2: %lli\n", part2(numbers,index-1, numbers[index]));

	return 0;
}

