#include "redBlackTree.h"

int main()
{
    int terminate = 1;
    char *str = malloc(sizeof(char)*255);
    char **numbers = malloc(sizeof(char*)*255);

    fgets(str, 255, stdin);
    char *token = strtok(str, ",");
    numbers[0] = token;
    int i = 0;
    
    while(token != NULL && terminate == 1)
    {
        token = strtok(NULL, ", \n");
        if(token[0] == 'X' || token[0] == 'x')
        {
            terminate = 0;
        }
        i++;
        numbers[i] = token;
    }

    runProgram(numbers, i);

    return 0;
}