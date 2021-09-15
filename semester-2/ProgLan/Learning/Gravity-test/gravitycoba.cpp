#include <graphics.h>

using namespace std;

int main(){
    float gravity = 0.98;
    float velocityA = 0;
    float time = 0;
    float height = 0;
    int displayh = 600;

    initwindow(300, displayh);

    while (true){
        height = 0.5 * gravity * time * time;
        circle(150, height, 20);
        if (height >= displayh){
            height = 0;
            time = 0;
            velocityA = 0;
        }
        time++;
        delay(20);
        cleardevice();
    }
}
