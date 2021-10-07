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

const char* ReadFile(const char* fileName)
{
    FILE* pFile = fopen(fileName, "r");
    const char* outContents;

    if (pFile == NULL)
    {
        printf("Could not load %s\n", fileName);
        return "Cringe";
    }

    while (fgets(outContents, sizeof(outContents), pFile));

    printf(outContents);

    fclose(pFile);

    return outContents;
}