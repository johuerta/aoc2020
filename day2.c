#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_LENGTH 256*sizeof(char)

int dayTwoPart2()
{
    int index1, index2;
    int occurrences = 0, validPasswords = 0;
    char letter;
    char *password = (char *) malloc(MAX_LENGTH);

    for(int passwords = 0 ;passwords<1000; passwords++)
    {
        memset(password, '\0', MAX_LENGTH);
        scanf("%i-%i %c: %s", &index1, &index2, &letter, password);
        //printf("%i %i %c %s\n", index1, index2, letter, password);
        if(password[index1-1] == letter) occurrences++;
        if(password[index2-1] == letter) occurrences++;
        if(occurrences == 1) validPasswords++;
        occurrences = 0;
    }

    printf("valid passwords = %i\n",validPasswords);
    free(password);
    return 0;
}

int dayTwoPart1()
{

    int lower, upper;
    int occurrences = 0, validPasswords = 0;
    char letter;
    char *password = (char *) malloc(MAX_LENGTH);

    for(int passwords = 0 ;passwords<1000; passwords++)
    {
        memset(password, '\0', MAX_LENGTH);
        scanf("%i-%i %c: %s", &lower, &upper, &letter, password);
        //printf("%i %i %c %s\n", lower, upper, letter, password);
        char *current = password;

        while(*current != '\0')
        {
            if(*current == letter)
            {
                occurrences++;
                if(occurrences > upper)
                    break;
            }
            current++;
        }
        if(occurrences >=  lower && occurrences <= upper)
            validPasswords++;

        occurrences = 0;
    }

    printf("valid passwords = %i\n",validPasswords);
    free(password);
    return 0;
}
int main()
{
        //dayTwoPart1();
        dayTwoPart2();
        return 0;
}
