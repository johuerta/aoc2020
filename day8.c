#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INSTRUCTION_COUNT 623

typedef struct instruction
{
	char *action;
	int value;
	int seen;
} Instruction;

char *jmp = "jmp";
char *nop = "nop";
char *acc = "acc";

int part1(Instruction **instructions)
{
	int currentIndex = 0;
	int acc = 0;
	int i = 0;
	printf("Visited ");
	for(currentIndex = 0; currentIndex < INSTRUCTION_COUNT; i++)
	{
		Instruction *currInst = instructions[currentIndex];
		printf("%i ", currentIndex);
		
		if(currInst->seen == 1)
		{
			// we found the loop
			printf("The loop is in %i\n",currentIndex);
			acc = INT_MAX;
			break;
		}
		else if(strcmp(currInst->action,"acc") == 0)
		{
			acc += currInst->value;
			currentIndex++;
		}
		else if(strcmp(currInst->action,"jmp") == 0)
		{
			currentIndex += currInst->value;
		}
		else if(strcmp(currInst->action,"nop") == 0)
        {
			currentIndex++;
        }
		else
		{
			printf("UNKNOWN ACTION? %s %i\n", currInst->action, currentIndex);
		}
		currInst->seen = 1;
	}	
	printf("Visited %i nodes\n", i);
	return acc;
}

void reset_seen(Instruction **instructions)
{
	for(int i = 0; i < INSTRUCTION_COUNT; i++)
	{
		Instruction *currInst = instructions[i];
		currInst->seen = 0;
	}
}

int part2(Instruction **instructions)
{
	int currentIndex = 0;
	int counter = 0;
	int invalid = 0;
	
	reset_seen(instructions);

	for(int i = 0; i < INSTRUCTION_COUNT; i++)
	{
		Instruction *currInst = instructions[i];
		counter = 0;
		if(strcmp(currInst->action, acc) == 0)
		{
			continue;
		}
		else if(strcmp(currInst->action, nop) == 0)
		{
			printf("Replacing 'nop'");
			currInst->action = jmp;
			//strcpy(currInst->action, "jmp");
			printf(" > '%s' %i\n", currInst->action, i);
			counter = part1(instructions);
			reset_seen(instructions);
			if(counter == INT_MAX)
			{
				printf("nope\n");
				// it's not this one
				currInst->action = nop;
				//strcpy(currInst->action, "nop");
				invalid = 1;
			}
		}
		else if(strcmp(currInst->action, "jmp") == 0)
		{
			printf("Replacing 'jmp'");
			currInst->action = nop;
			printf(" > '%s' %i\n", currInst->action,i);
			counter = part1(instructions);
			reset_seen(instructions);
			if(counter == INT_MAX)
			{
				printf("nope\n");
				// it's not this one
				currInst->action = jmp;
				invalid = 1;
			}
		}

		if(invalid == 0)
		{
			printf("%i %s\n", i, instructions[i]->action );
			return counter;
		}

		invalid = 0;
	}
	printf("nope\n");
	return counter;
}

void readInstructions(Instruction **instructions)
{
		char action[7];
		memset(action,0,7);
		int move;
		char moves[5];
		int instructionIndex = 0;

		while(scanf("%s %s",action,moves) > 0)
		{
			printf("%s - %s\n",action,moves);
			move = atoi(moves);
			instructions[instructionIndex] = (Instruction *) malloc(sizeof(Instruction *));
			Instruction *instruction = instructions[instructionIndex];
			instruction->action = strcmp(action,jmp) > 0 ? nop : strcmp(action,jmp) < 0 ? acc : jmp;
			instruction->value = move;
			instruction->seen = 0;
			instructionIndex++;
		}

}

int main(int argc, char **argv)
{
	Instruction *instructions[INSTRUCTION_COUNT];
	readInstructions(instructions);
	printf("part 1: %i\n", part1(instructions));
	printf("part 2: %i\n", part2(instructions));
	return 0;
}

