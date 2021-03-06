#include <graphics.h>
#include <math.h>

using namespace std;

int main(){
    float PI = M_PI;
    float k, r, x, y;

    int n = 4;
    int d = 97;
    int color;
    int height = 800;
    int width = 800;
    int originX = width / 2;
    int originY = height / 2;

    initwindow(width, height);

    for (float theta = 0; theta<=361; theta += 0.5){
        k = theta * PI/180;
        r = 300 * sin(n*k);
        x = r*cos(k) + originX;
        y = r*sin(k) + originY;
        color = rand() % 16 + 1;
        setcolor(color);
        circle(x, y, 10);
        delay(1);
    }
    getch();
}
