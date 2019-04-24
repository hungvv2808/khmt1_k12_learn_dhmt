#include <graphics.h>

void lineBressenham(int x1, int y1, int x2, int y2){
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int c = dx - dy;
    int c2 = 2*c;
    int x = x1, y = y1;
    int x_unit = 1, y_unit = 1;

    if(x2 - x1 < 0) x_unit = -x_unit;
    if(y2 - y1 < 0) y_unit = -y_unit;
    putpixel(x, y, GREEN);

    //duong thang dung
    if(x1 == x2){
        while(y != y2){
            y+=y_unit;
            putpixel(x, y, GREEN);
        }
    }
    else{
        // duong ngang
        if(y1 == y2){
            while(x != x2){
                x+=x_unit;
                putpixel(x, y, GREEN);
            }
        }
        else{
            // duong xien
            if(x1 != x2 && y1 != y2){
                while(x != x2 + 1){
                    delay(1);
                    if(c2 > -dy){
                        c-=dy;
                        x+=x_unit;
                    }
                    if(c2 < dx){
                        c+=dx;
                        y+=y_unit;
                    }
                    putpixel(x, y, GREEN);
                }
            }
        }
    }
}

int main(){
    int gd, gm = VGAMAX;
    gd = DETECT;
    initgraph(&gd, &gm, NULL);

    lineBressenham(100, 100, 300, 300);
    
    getch();
    closegraph();
}