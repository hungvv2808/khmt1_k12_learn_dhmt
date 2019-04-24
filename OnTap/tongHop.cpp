#include <graphics.h>

/* DUONG THANG */

//doi cho 2 diem
void swap(int a, int b){
    int tg = a;
    a = b;
    b = tg;
}

//- Bresenham:
/*
    +) m<-1:
    (Thuat toan)
    b1: neu yA > yB -> swap(yA, yB)
    b2: dx = xB - xA, dy = yB - yA;
        const1 = 2dx, const2 = 2*(dx + dy);
        p = 2dx+dy;
        diem dau tien: x = xA, y = yA;
    b3: ve (x, y)
    b4: y++
    b5: if(p<0) p+=const2, x--;
        else    p+=const1;
    b6: neu y <= yB quay lai B3
    b7: end
*/
void bresAm(int x1, int y1, int x2, int y2, int mau){
    if(y1 > y2){
        swap(x1, x2);
        swap(y1, y2);
    }
    int dx = x2 - x1, dy = y2 - y1;
    int const1 = 2*dx, const2 = 2*(dx+dy);
    int p = 2*dx + dy;
    int x = x1, y = y1;
    while(y <= y2){
        putpixel(x, y, mau);
        y++;
        if(p<0){
            p+=const2;
            x--;
        }
        else    p+=const1;
        delay(5);
    }
}

/*
    +) m > 1:
    (Thuat toan)
    b1: neu yA > yB -> swap(yA, yB)
    b2: dx = xB - xA, dy = yB - yA;
        const1 = 2dx, const2 = 2(dx - dy)
        p = 2dx - dy;
        diem dau tien: x = xA, y = yA;
    b3: ve (x, y)
    b4: y++
    b5: if(p<0) p+=const1;
        else    p+=const2, x++;
    b6: neu y <= yB quay lai b3
    b7: end
*/
void bresDuong(int x1, int y1, int x2, int y2, int mau){
    if (y1 > y2){
        swap(x1, x2);
        swap(y1, y2);
    }
    int dx = x2 - x1, dy = y2 - y1;
    int const1 = 2 * dx, const2 = 2 * (dx - dy);
    int p = 2 * dx - dy;
    int x = x1, y = y1;
    while(y<=y2){
        putpixel(x, y, mau);
        y++;
        if(p<0) p+=const1;
        else{
            p+=const2;
            x++;
        }
        delay(5);
    }
}

/*
    +) 0 < m <= 1:
    (Thuat toan)
    b1: neu xA>xB -> swap(xA, xB)
    b2: dx = xB - xA, dy = yB - yA;
        const1 = 2dy, const2 = 2(dy - dx)
        p = 2dy - dx;
        diem dau tien: x = xA, y = yA;
    b3: ve (x, y)
    b4: x++
    b5: if(p<0) p+=const1;
        else    p+=const2, y++;
    b6: neu x <= xB quay lai b3
    b7: end
*/
void bresKhongMot(int x1, int y1, int x2, int y2, int mau){
    if(x1 > x2){
        swap(x1, x2);
        swap(y1, y2);
    }
    int dx = x2 - x1, dy = y2 - y1;
    int const1 = 2 * dy, const2 = 2 * (dy - dx);
    int p = 2 * dy - dx;
    int x = x1, y = y1;
    while(x <= x2){
        putpixel(x, y, mau);
        x++;
        if(p<0) p+=const1;
        else{
            p+=const2;
            y++;
        }
        delay(5);
    }
}

/*
    +) -1 <= m < 0:
    (Thuat toan)
    b1: neu xA>xB -> swap(xA, xB)
    b2: dx = xB - xA, dy = yB - yA;
        const1 = 2dy, const2 = 2(dy + dx)
        p = 2dy + dx;
        diem dau tien: x = xA, y = yA;
    b3: ve (x, y)
    b4: x++
    b5: if(p<0) p+=const2, y--;
        else    p+=const1;
    b6: neu x <= xB quay lai b3
    b7: end
*/
void bresAmMotKhong(int x1, int y1, int x2, int y2, int mau){
    if (x1 > x2){
        swap(x1, x2);
        swap(y1, y2);
    }
    int dx = x2 - x1, dy = y2 - y1;
    int const1 = 2 * dy, const2 = 2 * (dy + dx);
    int p = 2 * dy + dx;
    int x = x1, y = y1;
    while (x <= x2){
        putpixel(x, y, mau);
        x++;
        if (p < 0){
            p += const2;
            y--;
        }
        else    p += const1;
        delay(5);
    }
}


// mid point
/*
    (Thuat toan)
    b1: dx = -(x2 - x1), dy = y2 - y1;
        p = dx/2 + dy;
        x = x1, y = y1;
    b2: ve (x, y)
    b3: x++
    b4: if(p<0) p+=dy;
        else    p+=dx+dy, y++;
    b5: neu x <= x2 quay lai b3
    b6: end
*/
void midPoint(int x1, int y1, int x2, int y2, int mau){
    int dx = -(x2 - x1), dy = y2 - y1;
    int p = dx/2 + dy;
    int x = x1, y = y1;
    while(x <= x2){
        putpixel(x, y, mau);
        x++;
        if(p<0) p+=dy;
        else{
            p+=dx+dy;
            y++;
        }
        delay(5);
    }
}

/* HINH TRON */

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

/*
    Bresenham
    b1: diem dau tien x = 0, y = r
        p = 3 - 2r
    b2: ve 8 diem
    b3: if(p<0) p+=4x+6
        else    p+=4(x-y)+10, y--;
    b4: x++
    b5: neu x <= y quay lai b2
    b6: end
*/
void bresCircle(int x1, int y1, int r, int mau){
    int x = 0, y = r;
    int p = 3 - 2*r;
    while(x<=y){
        ve8diem(x1, y1, x, y, mau);
        if(p<0) p+=4*x+6;
        else{
            p+=4*(x-y)+10;
            y--;
        }
        x++;
        delay(5);
    }
}

/*
    Midpoint
    b1: diem dau tien x = 0, y = r
        p = 1 - r
    b2: ve 8 diem
    b3: if(p<0) p+=2x+3
        else    p+=2(x-y)+5, y--;
    b4: x++
    b5: neu x <= y quay lai b2
    b6: end
*/
void midCircle(int x1, int y1, int r, int mau){
    int x = 0, y = r;
    int p = 1 - r;
    while (x <= y){
        ve8diem(x1, y1, x, y, mau);
        if (p < 0)
            p += 2 * x + 3;
        else{
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
        delay(5);
    }
}

/* TO MAU LOANG */
void loang(int x, int y, int mauBien, int mauTo){
    int mauHienTai = getpixel(x, y);
    if (mauHienTai != mauBien && mauHienTai != mauTo){
        putpixel(x, y, mauTo);
        loang(x - 1, y, mauBien, mauTo);
        loang(x + 1, y, mauBien, mauTo);
        loang(x, y - 1, mauBien, mauTo);
        loang(x, y + 1, mauBien, mauTo);
    }
}

/* TO MAU BIEN */
/*
  (Thuat toan)
  b1: Tim bien trai nhat va bien phai nhat
    x = x1, y = y1;
    while (mau(x1-1,y)!=mb) x1=x1-1;
    while (mau(x2+1,y)!=mb) x2=x2+1;
  b2: ve doan (x1, y) va (x2, y) bang mau to (mt)
  b3: Tinh diem phat trien tiep theo:
    while(mau(x1,y+i)=mb) x1=x1+1;
  b4: neu x1 <= x2 thi:
    x = x1, y+=i;
    quay lai b1
  b5: end
*/
/*void toMauTheoDuongBien(int x, int y, int mauto, int maubien)
{
    int x1, x2;
    do
    {
        x1 = x;
        x2 = x;
        while (getpixel(x1 - 1, y) != maubien)
            x1--;
        while (getpixel(x2 + 1, y) != maubien)
            x2++;
        //line
        for (int i = x1; i <= x2; i++)
            putpixel(i, y, mauto);
        while (getpixel(x1, y + 1) == maubien)
            x1++;
        if (x1 <= x2)
        {
            x = x1;
            y = y + 1;
        }
    } while (x1 <= x2);
    do{
            x1 = x;
            x2 = x;
            while (getpixel(x1 - 1, y) != maubien)
                x1--;
            while (getpixel(x2 + 1, y) != maubien)
                x2++;
            //line
            for (int i = x1; i <= x2; i++)
                putpixel(i, y, mauto);
            while (getpixel(x1, y - 1) == maubien)
                x1++;
            if (x1 <= x2)
            {
                x = x1;
                y = y - 1;
            }
        }
    while (x1 <= x2);
}*/

int main(){
        int gd, gm = VGAMAX;
        gd = DETECT;
        initgraph(&gd, &gm, NULL);
        //duong thang
        bresAm(100, 100, 300, 300, 10);
        bresDuong(100, 100, 300, 300, 11);
        bresKhongMot(100, 100, 270, 270, 12);
        bresAmMotKhong(100, 100, 300, 300, 13);
        midPoint(100, 100, 400, 450, 15);

        //duong tron
        midCircle(100, 100, 70, 17);
        loang(70, 70, 15, 12);
        bresCircle(100, 100, 50, 15);
        loang(100, 100, 15, 10);
        getch();
        closegraph();
    }
