#include <graphics.h>

void midPoint(int x1, int y1, int x2, int y2, int mau){
    int a = y2 - y1, b = - x2 + x1;
    int p = a + b/2;
    int x = x1, y = y1;
    while(x <= x2){
        putpixel(x, y, mau);
        x++;
        if(p<0) p+=a;
        else{
            p+=a+b;
            y++;
        }
        delay(20);
    }
}

int main(){
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    midPoint(100, 150, 400, 350, 10);
    getch();
    closegraph();
}