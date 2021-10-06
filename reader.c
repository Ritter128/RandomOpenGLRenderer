#include "reader.h"
#include <stdio.h>

const char* ReadFile(const char* fileName)
{
    FILE* pFile = fopen(fileName, "r");
    const char* fileContents;
    char currentChar;

    if (pFile == NULL)
    {
        printf("Could not load %s\n", fileName);
        return "Cringe";
    }

    while ((currentChar = fgetc(pFile)) != EOF)
    {
        fscanf(pFile, fileContents);
    }

    fclose(pFile);\

    return fileContents;
}