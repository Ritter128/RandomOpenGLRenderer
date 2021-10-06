#include <stdio.h>
#include "file.h"

File OpenFile(char* path)
{
    File file = {0};
    file.path = path;

    printf("Opened %s\n", file.path);
    return file;
}

void CloseFile(File file)
{
    printf("File %s has been closed\n", file.path);
}