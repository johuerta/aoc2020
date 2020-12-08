#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char line[27];
	char *current = NULL;
	int currentIndex = 0;
	int questions[26];
	int totalSum = 0;
	int groupYes = 0;
	int groupCounter = 0;
			
	memset(questions,0,27*sizeof(int));
	
	FILE *fp = fopen("/home/jorge/aoc2020/inputs/day6", "r");

	while(fgets(line,28,fp) != NULL)
	{
		current = line;
		printf("%c %s\n",*current,line);
		if(*current < 'a' || *current > 'z')
		{
			// new group
			int missingCounter = 0;
			for(int i = 0; i < 26; i++)
			{
				if(questions[i] > 0) 
						groupYes++;		
				else
				{
					printf("%c",i+'a');
					missingCounter++;
				}

			}
			totalSum += groupYes;
			memset(questions,0,27*sizeof(int));
			groupYes = 0;
			groupCounter++;
			continue;
		}

		while(*current >= 'a' && *current <= 'z')
		{
			currentIndex = *current - 'a';
			questions[currentIndex]++;
			current++;
		}
		

	}

	for(int i = 0; i < 26; i++)
	{
		if(questions[i] > 0) groupYes++;		
	}
	printf("group %i had %i yes\n",groupCounter,groupYes);
	totalSum += groupYes;

	printf("Total sum = %i\n", totalSum);

	fclose(fp);

	return 0;
}

