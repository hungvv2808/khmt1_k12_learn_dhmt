#include <graphics.h>
#include <math.h>

float xwmin, ywmin, xwmax, ywmax;
float tlx, tly;
int   xvmin, yvmin, xvmax, yvmax;
void cuaso(float x1, float y1, float x2, float y2)
{
    xwmin = x1; ywmin = y1; xwmax = x2; ywmax = y2;
}
void khungnhin(int x1, int y1, int x2, int y2)
{
    xvmin = x1; yvmin = y1; xvmax = x2; yvmax = y2;
    tlx = (xvmax - xvmin)/(xwmax - xwmin);
    tly = (yvmax - yvmin)/(ywmax - ywmin);
}
void chuyenden2d(float x, float y)
{
    int xm = (int)(tlx*(x-xwmin)+xvmin+0.5);
    int ym = (int)(tly*(ywmax-y)+yvmin+0.5);
    moveto(xm,ym);
}
void veden2d(float x, float y)
{
    int xm = (int)(tlx*(x-xwmin)+xvmin+0.5);
    int ym = (int)(tly*(ywmax-y)+yvmin+0.5);
    lineto(xm,ym);
}
void tinhtien(float x, float y, float m, float n, float &x1, float &y1)
{
    x1 = x+m;
    y1 = y+n;
}
void quaytaiO(float x, float y, float alpha, float &x1, float &y1)
{
    alpha = alpha*3.14/180;
    x1 = x*cos(alpha)-y*sin(alpha);
    y1 = y*sin(alpha)+y*cos(alpha);
}
void biendoitile(float x, float y, float tlx, float tly, float &x1, float &y1)
{
    x1 = tlx*x;
    y1 = tly*y;
}
void vedothi(float xwmin, float xwmax)
{
    float x = xwmin;
    float dx = 0.01;
    float y = sin(x);
    chuyenden2d(x,y);
    while(x<=xwmax)
    {
        x+=dx;
        y = sin(x);
        veden2d(x,y);
    }
}
void phepdoixungtam(float x, float y, float alpha, float m, float n, float &x1, float &y1)
{
    float x11,y11, x12,y12;
    tinhtien(x,y,-m,-n,x11,y11);
    quaytaiO(x11,y11,alpha,x12,y12);
    tinhtien(x12,y12,m,n,x1,y1);
}
void veanhdothi(float xwmin, float xwmax)
{
    float x1,y1;
    float x = xwmin;
    float dx = 0.01;
    float y = sin(x);
    phepdoixungtam(x,y,180,0,-2,x1,y1);
    chuyenden2d(x1,y1);
    while (x <= xwmax)
    {
        x += dx;
        y = sin(x);
        phepdoixungtam(x, y, 180, 2, -2, x1, y1);
        veden2d(x1, y1);
    }
}
int main()
{
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);
    cuaso(-3*3.14,-1.5,4*3.14,1.5);
    khungnhin(50,50,450,400);
    setcolor(4);
    vedothi(-2*3.14,3*3.14);
    getch();
    setcolor(7);
    veanhdothi(-2*3.14, 3*3.14);
    getch();
    closegraph();
}