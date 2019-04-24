#include <graphics.h>
#include <stdio.h>
#define Round(a) (int)(a+0.5)

int color = RED;
struct point{
    int x, y;
};

//DDA
void lineDDA(int x1, int y1, int x2, int y2, int color){
    int x_unit = 1;
    int dx = x2 - x1, dy = y2 - y1;
    int x = x1;
    float y = y1;
    float y_unit = 1;

    if(dx < 0)  x_unit
}