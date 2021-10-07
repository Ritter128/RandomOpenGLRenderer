#include "reader.h"
#include <stdio.h>

char* ReadFile(const char* fileName)
{
    FILE* pFile = fopen(fileName, "r");
    char fileContents[500];
    char currentChar;

    if (pFile == NULL)
    {
        printf("Could not load %s\n", fileName);
        return "Cringe";
    }

    int iterator = 0;
    while ((currentChar = fgetc(pFile)) != EOF)
    {
        //printf("%s\n", fileContents);
        //printf("%c\n", currentChar);
        fileContents[iterator] = currentChar;
        iterator++;   
    }

    fclose(pFile);

    return fileContents;
}