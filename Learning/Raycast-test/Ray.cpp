#include <graphics.h>
#include <math.h>


int distanceX(int x){
    return x-500;
}

float rad(int arc, int x){
    return tan(arc) * distanceX(x);
}

int main(){
    const int canvas = 500;

    initwindow(canvas, canvas);

    while(true){
        fillellipse(mousex(), mousey(), 5, 5);
        for (int i = 0; i<=360; i++){
            line(mousex(), mousey(), i>180?0:canvas, mousey()-rad(i, mousex()));
        }
        delay(1);
        cleardevice();
    }


    getch();
}
