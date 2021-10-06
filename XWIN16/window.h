#pragma once

struct Window
{
    int x,y;
    int w,h;
    char* name;
};

struct Window CreateWindow(
    int x, int y, 
    int w, int h, 
    char* name
);