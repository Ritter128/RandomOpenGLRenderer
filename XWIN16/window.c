#include "window.h"

struct Window CreateWindow(
    int x, int y, 
    int w, int h,
    char* name)
{
    struct Window win = {x, y, w, h, name};

    return win;
}