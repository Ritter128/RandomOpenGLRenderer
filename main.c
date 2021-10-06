#include <stdio.h>
#include "window.h"
#include "file.h"
#include "obama.h"
#include "biden.h"

int main(void)
{
    struct Window mainWindow = CreateWindow(
        300, 300, 600, 400, 
        "Main Window"
    );
    
    printf("%s\n", mainWindow.name);

    File myFile = OpenFile("dicks/hentai/seggs.png");

    CloseFile(myFile);

    ObamaSeggs();
    BidenSeggs();

    return 0;
}