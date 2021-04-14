#include <graphics.h>
#include <iostream>
#include <math.h>

#define FILL    1
#define COLOR   2

using namespace std;

/*Prototype Function*/
int originy(int y);
void resetColor(int reset);
void rect(int x, int y, int w, int h, int color=0, int style=0, int border=15);
void handDraw(int x, int y, int point[], int numpoint, int color=0, int style=0);
void drawBezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void drawLine(int x1, int y1, int x2, int y2, int color=15);
void drawRoad(int x);
void drawBuilding_1(int x, int y);
void drawBurjArab(int x=0, int y=0);
void drawMonas(int x, int y);
void drawBuilding_2(int x, int y);
void drawBallon(int x, int y);
void drawScene(int *arr, int x, int arrsize);
void randomize(int *arr, int arrsize);
void drawCloud(int x, int y, float scale);
/*END OF Prototype Function*/

class Cloud{
private:
    int cloudSize[6];
    int xOff[6];
    int yOff[6];
    float xLoc, yLoc;
    float speed;
public:
    Cloud(){
        //create new cloud
        newCloud();
    }
    void drawCloud(float x=0){
        setfillstyle(SOLID_FILL, WHITE);
        for(int i; i<6; i++){
            fillellipse(xOff[i]+x, yOff[i]+yLoc, cloudSize[i], cloudSize[i]);
        }
        resetColor(FILL);
    }
    void moveCloud(){
        xLoc = xLoc - speed;
        drawCloud(xLoc);
        if (xLoc <= -50){
            newCloud();
        }
    }
    void newCloud(){
        for (int i = 0; i<6; i++){
                cloudSize[i] = 20 + rand()% 20+1;
                xOff[i] = -25 + rand()% 50+1;
                yOff[i] = -15 + rand()% 30+1;
        }
        yLoc = rand() % 280 + 1;
        xLoc = getmaxx() + 50 + rand()%20 + 1;
        speed = (float)(2 + rand() % 8 + 1)/10;
    }
};

int main(){
    const int cheight = 800;
    const int cwidth = 600;

    initwindow(cwidth, cheight);

    int yb = 0;
    int buildingOrder[4] = {1, 4, 3, 2};
    int fheight = 25;
    float yf = 0;
    bool returning = true;
    Cloud cloud[5];

    while (!kbhit()){
        for (int i=0; i>=-getmaxx(); i--){
            if (!returning){
                yf += 0.2;
                if (yf>=fheight){
                    returning = true;
                }
            }
            else if (returning){
                yf -= 0.2;
                if (yf<=0){
                    returning = false;
                }
            }
            drawRoad(i);
            drawRoad(i+getmaxx());
            drawScene(buildingOrder, i, 4);
            drawScene(buildingOrder, i+getmaxx(), 4);
            drawBallon(70, 500+yf);
            cloud[0].moveCloud();
            cloud[1].moveCloud();
            cloud[2].moveCloud();
            cloud[3].moveCloud();
            cloud[4].moveCloud();
            delay(1);
            cleardevice();
            //cout << mousey() << " " << mousex() << endl;
        }
    }
    getch();
    return 0;
}

/*=================MY OWN DRAWING FUNCTION==================*/
int originy(int y){
    //set y coordinate origin to left bottom
    return getmaxy() - y;
}

void resetColor(int reset){
    //reset color to original
    switch(reset){
    case 1: setfillstyle(0, 0); break;
    case 2: setcolor(15); break;
    default: break;
    }
}

void rect(int x, int y, int w, int h, int color, int style, int border){
    //draw rectangle by defining x, y, width, height, color, and border
    y = originy(y);
    rectangle(x, y-h, x+w ,y);
    setfillstyle(style, color);
    floodfill(x+1, y-1, border);
    resetColor(FILL);
}

void handDraw(int x, int y, int point[], int numpoint, int color, int style){
    //transform coordinate to determined coordinate
    for (int i=0; i<numpoint*2; i+=2){
        point[i] = point[i] + x;
        point[i+1] = originy(point[i+1] + y);
    }

    drawpoly(numpoint, point);
    setfillstyle(style, color);
    fillpoly(numpoint, point);
    resetColor(FILL);
}

void drawBezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    float x, y, t, t2, x_2, y_2;
    y1 = originy(y1);
    y2 = originy(y2);
    y3 = originy(y3);
    y4 = originy(y4);
    for (float t = 0; t<=1.1; t+=0.1){
        x = pow((1-t), 3)*x1 + 3*pow((1-t),2)*t*x2 + 3*(1-t)*pow(t, 2)*x3 + pow(t, 3)*x4;
        y = pow((1-t), 3)*y1 + 3*pow((1-t),2)*t*y2 + 3*(1-t)*pow(t, 2)*y3 + pow(t, 3)*y4;
        //cout << x << " " << y << endl;
        if (t>0) line(x_2, y_2, x, y);
        x_2 = x;
        y_2 = y;
        //putpixel(x+1, y+1, WHITE);
        //cout << t << endl;
    }
}

void drawLine(int x1, int y1, int x2, int y2, int color){
    y1 = originy(y1);
    y2 = originy(y2);

    setcolor(color);
    line(x1, y1, x2, y2);
    resetColor(COLOR);
}
/*=================END OF MY OWN DRAWING FUNCTION===================*/

/*==========================OTHER FUNCTION==========================*/

void drawScene(int *arr, int x, int arrsize){
    for(int i = 0; i<arrsize; i++){
        switch(arr[i]){
            case 1: drawBuilding_1(150*i+x, 130); break;
            case 2: drawBuilding_2(150*i+x, 130); break;
            case 3: drawMonas(150*i+x, 130); break;
            case 4: drawBurjArab(150*i+x, 130); break;
        }
    }
}

void randomize(int *arr, int arrsize){
    for (int i = 0; i<arrsize; i++){
        arr[i] = rand() % 4 + 1;
    }
}

/*=======================END OF OTHER FUNCTION======================*/

/*To draw function*/
void drawRoad(int x){
    const int stripSpace = 15;
    const int stripTotal = 7;
    const int stripHeight = 15;
    const int stripLenght = (getmaxx() - stripTotal*stripSpace)/stripTotal;
    const int roadHeight = 130;

    rect(0, 0, getmaxx(), roadHeight);

    for (int i = 0; i<stripTotal; i++){
        rect(stripLenght*i+stripSpace*i+x, (roadHeight/2)-(stripHeight/2), stripLenght, stripHeight, WHITE, 3);
    }
}

void drawBuilding_1(int x=0, int y=0){
    float sc = 0.75;

    rect(5+x, 0+y, 200*sc, 353*sc);
    rect(5+x, 0+y, 200*sc, 68*sc);
    drawLine(51*sc+x, 0+y, 51*sc+x, 353*sc+y);
    drawLine(67*sc+x, 0+y, 67*sc+x, 353*sc+y);
    drawLine(82*sc+x, 0+y, 82*sc+x, 353*sc+y);
    drawLine(100*sc+x, 0+y, 100*sc+x, 353*sc+y);
}

void drawBurjArab(int x, int y){
    int dasar[] = {0,0, 150,0, 138,8, 12,8,0,0};

    drawBezier(27+x, 272+y, 114+x, 205+y, 135+x, 97+y, 115+x, 8+y);
    drawLine(27+x, 272+y, 27+x, 8+y);
    //Jendela atas
    drawBezier(41+x, 250+y, 59+x, 231+y, 74+x, 209+y, 88+x, 183+y);
    drawLine(41+x, 250+y, 41+x, 183+y);
    drawLine(41+x, 183+y, 88+x, 183+y);
    drawLine(41+x, 191+y, 82+x, 191+y);
    //Jendela Tengah1
    drawBezier(90+x, 175+y, 97+x, 160+y, 102+x, 144+y, 105+x, 127+y);
    drawLine(90+x, 175+y, 41+x, 175+y);
    drawLine(41+x, 175+y, 41+x, 127+y);
    drawLine(41+x, 127+y, 105+x, 127+y);
    //jendela tengah2
    drawBezier(107+x, 120+y, 110+x, 104+y, 111+x, 88+y, 112+x, 71+y);
    drawLine(107+x, 120+y, 41+x, 120+y);
    drawLine(41+x, 120+y, 41+x, 71+y);
    drawLine(41+x, 71+y, 112+x, 71+y);
    //jendela bawah
    drawBezier(112+x, 62+y, 111+x, 45+y, 110+x, 27+y, 106+x, 8+y);
    drawLine(112+x, 62+y, 41+x, 62+y);
    drawLine(41+x, 62+y, 41+x, 8+y);
    drawLine(41+x, 8+y, 106+x, 8+y);
    //balkon
    rect(94+x, 192+y, 15, 4);
    drawLine(98+x, 186+y, 105+x, 192+y);
    //gambar dsar gedung
    handDraw(x, y, dasar, 5);
}

void drawMonas(int x, int y){
    int batang[] = {61,52, 68,231, 59,231, 56,236, 56,237, 94,237, 94,236, 91,230, 81,230, 89,52, 61,52};

    rect(26+x, 0+y, 97, 15);
    drawBezier(45+x, 15+y, 38+x, 26+y, 22+x, 38+y, 8+x, 44+y);
    drawBezier(105+x, 15+y, 112+x, 26+y, 127+x, 38+y, 142+x, 44+y);
    rect(0+x, 44+y, 150, 8);
    handDraw(x, y, batang, 11);
    //EMAS
    drawBezier(75+x, 266+y, 78+x, 260+y, 77+x, 244+y, 84+x, 237+y);
    drawBezier(75+x, 266+y, 71+x, 260+y, 73+x, 244+y, 65+x, 237+y);
    //setfillstyle(CLOSE_DOT_FILL, YELLOW);
    //floodfill(77+x, 744, 15);
    //resetColor(FILL);
}

void drawBuilding_2(int x, int y){
    rect(65+x, 0+y, 77, 288);
    drawLine(65+x, 288+y, 29+x, 288+y);
    drawBezier(65+x, 288+y, 9+x, 288+y, 9+x, 288+y, 9+x, 268+y);
    drawLine(9+x, 268+y, 9+x, 0+y);
    rect(74+x, 0+y, 60, 235, WHITE, LINE_FILL);
}

void drawBallon(int x, int y){


    rect(56+x, 0+y, 38, 19);
    rect(54+x, 19+y, 42, 7);
    rect(59+x, 70+y, 30, 3);
    drawLine(75+x, 26+y, 75+x, 70+y);
    drawLine(56+x, 26+y, 59+x, 70+y);
    drawLine(94+x, 26+y, 89+x, 70+y);
    drawBezier(59+x, 73+y, 4+x, 126+y, -27+x, 219+y, 75+x, 223+y);
    drawBezier(90+x, 73+y, 145+x, 126+y, 176+x, 219+y, 75+x, 223+y);
    setfillstyle(CLOSE_DOT_FILL, RED);
    floodfill(58+x, originy(y+150), 15);
    resetColor(FILL);
}

void drawCloud(int x, int y, float scale){
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse((101+x)*scale, (744-y)*scale, 43*scale, 43*scale);
    fillellipse((54+x)*scale, (745-y)*scale, 17*scale, 17*scale);
    fillellipse((32+x)*scale, (767-y)*scale, 32*scale, 24*scale);
    fillellipse((68+x)*scale, (775-y)*scale, 24*scale, 25*scale);
    fillellipse((99+x)*scale, (782-y)*scale, 19*scale, 14*scale);
    fillellipse((140+x)*scale, (780-y)*scale, 30*scale, 20*scale);
    fillellipse((171+x)*scale, (767-y)*scale, 19*scale, 19*scale);
    fillellipse((145+x)*scale, (765-y)*scale, 25*scale, 25*scale);
    resetColor(FILL);

}
