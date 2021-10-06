#pragma once

struct _File 
{
    int size;
    char* path;
    char* content;
    char type;
};
typedef struct _File File;

File OpenFile(char* path);
void CloseFile(File file);