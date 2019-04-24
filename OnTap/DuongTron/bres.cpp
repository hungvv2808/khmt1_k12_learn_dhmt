#include <graphics.h>

void ve8diem(int x1, int y1, int x, int y, int mau){
    putpixel(x1 + y, y1 - x, mau); //goc 1
    putpixel(x1 + x, y1 - y, mau); //goc 2
    putpixel(x1 - x, y1 - y, mau); //goc 3
    putpixel(x1 - y, y1 - x, mau); //goc 4
    putpixel(x1 - y, y1 + x, mau); //goc 5
    putpixel(x1 - x, y1 + y, mau); //goc 6
    putpixel(x1 + x, y1 + y, mau); //goc 7
    putpixel(x1 + y, y1 + x, mau); //goc 8
}

void bres(int x1, int y1, int r, int mau){
    int x = 0, y = r;
    int p = 3 - 2 * r;
    do{
        ve8diem(x1, y1, x, y, mau);
        if(p>0){
            p+=(4*(abs(x) - abs(y)) + 10);
            y--;
        }
        else    p+=(4*abs(x)+6);
        x++;
        delay(50);
    }   while(abs(x) <= abs(y));
}

int main(){
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    bres(200, 200, 50, 15);
    getch();
    closegraph();
}