#include <graphics.h>
#include <stdio.h>
#define Round(a) (int)(a + 0.5)
int color = RED;

// diem gom tung do x va hoanh do y
struct point{
    int x, y;
};

void lineDDA(int x1, int y1, int x2, int y2, int color) // DDA{
    int x_unit = 1, Dx = x2 - x1, Dy = y2 - y1;
    int x = x1;
    float y = y1;
    float y_unit = 1;

    if (Dx < 0) x_unit = -1;
    if (Dy < 0) y_unit = -1;
    // duong thang dung
    if (x1 == x2){
        while (y != y2)
        {
            y += y_unit;
            putpixel(x, Round(y), color);
        }
    }
    // duong ngang
    else{
        if (y1 == y2){
            while (x != x2){
                x += x_unit;
                putpixel(x, Round(y), color);
            }
        }
        else{
            // duong xien
            if (x1 != x2 && y1 != y2){
                float m = (float)abs(Dy) / abs(Dx);
                x_unit = 1;
                y_unit = m;
                x = x1;
                y = y1;

        if (Dx < 0)
            x_unit = -1; // ve x giam
        if (Dy < 0)
            y_unit = -m; // ve y giam

        putpixel(x, Round(y), color);
        while (x != x2)
        {
            x += x_unit;
            y += y_unit;
            putpixel(x, Round(y), color);
        }
    }
}

int main(){
    int x1, y1, x2, y2; int color;
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    lineDDA(50, 100, 200, 300, 15);
    getch();
    closegraph();
    return 0;
}