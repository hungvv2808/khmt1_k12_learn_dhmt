#include <graphics.h>

void bresenham3(int x1, int y1, int x2, int y2, int mau)
{
    if(y1>y2)
    {
        int tg = x1; x1 = x2; x2 = tg;
            tg = y1; y1 = y2; y2= tg;
    }
    int A = y2-y1;
    int B=-(x2-x1);
    int const1 = -2*B;
    int const2 = -2*B+2*A;
    int p = -2*B+A;
    int x =x1;
    int y = y1;
    while(y<=y2)
    {
        delay(0.001);
        putpixel(x,y,mau);
        if(p<0)
        {
            x--;
            p+=const2;
        }
        else p+=const1;
        y++;
    }

}
void bresenham33(int x1, int y1,int x2,int y2, int mau)
{
    if(x1>x2)
    {
        int tg = x1; x1 = x2; x2 =tg;
            tg = y1; y1 = y2; y2 = tg;
    }
    int dx  = x2-x1;
    int dy = y2-y1;
    int const1 = 2*dy;
    int const2 = 2*dy-2*dx;
    int p = 2*dy -dx;
    int x = x1; int y = y1;
    while(x<=x2)
    {
        putpixel(x,y,mau);
        if(p<0)
            p+=const1;
        else
        {
            y++;
            p+=const2;
        }
        x++;
        
    }
}
int main()
{
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    //bresenham3(100,30,50,100,5);
    bresenham33(0,0,400,400,5);
    getch();
    closegraph();
}