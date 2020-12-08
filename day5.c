#include <stdio.h>
#include <stdlib.h>

int main()
{

	char line[64];
	int seatID = 0;
	char *current = NULL;
	int highest = 0;
	int seats[1024];

	while(scanf("%s", line) > 0)
	{
		current = line;
		while(*current != '\0')
		{
			seatID = (seatID << 1) + 
					 ((*current == 'B' || *current == 'R') ? 1 : 0);
			current++;
		}
		
		if(seatID > highest) highest = seatID;
		seats[seatID] = 1;
		seatID = 0;
	}
	printf("highest = %i\n", highest);

	for(int i = 1; i < highest; i++)
	{
		if((seats[i] != 1) && (seats[i-1] == 1) && (seats[i+1] == 1))
		{
			printf("my seat = %i\n",i);
		}
	}

	return 0;
}

