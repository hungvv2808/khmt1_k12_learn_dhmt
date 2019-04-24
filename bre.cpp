#include <graphics.h>
#define DELAY 10
int color = 2;
void lineBresenham_1(int x1, int y1, int x2, int y2)
{
    int c2, c, Dx, Dy, x, y;
    Dx = abs(x2 - x1);
    Dy = abs(y2 - y1);
    c = Dx - Dy;
    c2 = 2 * c;
    x = x1;
    y = y1;

    int x_unit = 1, y_unit = 1;

    if (x2 - x1 < 0)
        x_unit = -x_unit;
    if (y2 - y1 < 0)
        y_unit = -y_unit;

    putpixel(x, y, GREEN);

    if (x1 == x2) // duong thang dung
    {
        while (y != y2)
        {delay(1);
            y += y_unit;
            putpixel(x, y, GREEN);
        }
    }

    else if (y1 == y2) // duong ngang
    {
        while (x != x2)
        {
            x += x_unit;
            putpixel(x, y, GREEN);
        }
    }

    else if (x1 != x2 && y1 != y2) // duong xien
    {
        while (x != x2 + 1)
        {
            delay(1);
            c2 = 2 * c;
            if (c2 > -Dy)
            {
                c = c - Dy;
                x = x + x_unit;
            }
            if (c2 < Dx)
            {
                c = c + Dx;
                y = y + y_unit;
            }
            putpixel(x, y, GREEN);
        }
    }
}

int main(){
    int x1,y1,x2,y2;
    int gd,gm=VGAMAX; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    lineBresenham_1(250, 300,250,100);
    getch();
    //delay(2);
    closegraph();
    return 0;
}