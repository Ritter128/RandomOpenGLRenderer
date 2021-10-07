#include "reader.h"
#include <stdio.h>
#include <string.h>

/*
char buffer[100];
FILE *fp = fopen("filename", "r");                 // do not use "rb"
while (fgets(buffer, sizeof(buffer), fp)) {
... do something
}
fclose(fp);
*/

char* ReadFile(const char* fileName)
{
    FILE* pFile = fopen(fileName, "r");
    char fileContents[500];
    char* outContents;

    if (pFile == NULL)
    {
        printf("Could not load %s\n", fileName);
        return "Cringe";
    }

    while (fgets(fileContents, sizeof(fileContents), pFile));

    fclose(pFile);

    strcpy(fileContents, outContents);

    return outContents;
}