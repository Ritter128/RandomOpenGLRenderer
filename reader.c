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
    char* outContents;
    int fileSize;

    if (pFile == NULL)
    {
        printf("Could not load %s\n", fileName);
        return "Cringe";
    }

    fseek(pFile, 0, SEEK_END);
    fileSize = ftell(pFile);
    rewind(pFile);

    printf("File size: %d\n", fileSize);

    outContents = (char*)malloc(sizeof(char) * (fileSize+1));
    fread(outContents, sizeof(char), fileSize, outContents);
    outContents[fileSize] = '\0';

    printf(outContents);

    fclose(pFile);

    return outContents;
}