#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
void put8pixel(int xc, int yc, int x, int y, int color)
{
    putpixel(x + xc, y + yc, color);
    putpixel(-x + xc, y + yc, color);
    putpixel(x + xc, -y + yc, color);
    putpixel(-x + xc, -y + yc, color);
    putpixel(y + xc, x + yc, color);
    putpixel(-y + xc, x + yc, color);
    putpixel(y + xc, -x + yc, color);
    putpixel(-y + xc, -x + yc, color);
}

void midpoint(int xc, int yc, int r, int color)
{
    int x = 0;
    int y = r;
    int f = 1 - r;
    put8pixel(xc, yc, x, y, color);
    while (x < y)
    {
        delay(10);
        if (f < 0)
            f += (x << 1) + 3;
        else
        {
            y--;
            f += ((x - y) << 1) + 5;
        }
        x++;
        put8pixel(xc, yc, x, y, color);
    }
}

int main()
{
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    midpoint(300,300,100, 15);
    getch();
}