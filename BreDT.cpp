#include <graphics.h>
#include <stdio.h>

void ve8diem(int x, int y, int x0, int y0, int maubien)
{                                      //ve 8 diem doi xung
    putpixel(x0 + x, y0 + y, maubien); //goc 4
    putpixel(x0 + x, y0 - y, maubien); //goc 1
    putpixel(x0 - x, y0 + y, maubien); //goc 5
    putpixel(x0 - x, y0 - y, maubien); //goc 8
    putpixel(x0 + y, y0 + x, maubien); //goc 3
    putpixel(x0 + y, y0 - x, maubien); //goc 2
    putpixel(x0 - y, y0 + x, maubien); //goc 6
    putpixel(x0 - y, y0 - x, maubien); //goc 7
}

void Bre1_dt(int x0, int y0, int R, int maubien)
{
    int x = 0, y = R;
    float P = 3 - 2 * R;
    do
    {
        ve8diem(x, y, x0, y0, maubien);
        if (P < 0)
            P = P + 4 * abs(x) + 6;
        else
        {
            P = P + 4 * (abs(x) - abs(y)) + 10;
            y--;
        }
        x++;
        delay(50);
    } while (abs(x) <= abs(y));
}

int main(){
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    Bre1_dt(100, 100, 100, 15);
    delay(10);
}