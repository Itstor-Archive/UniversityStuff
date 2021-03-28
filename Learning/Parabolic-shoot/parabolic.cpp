#include <graphics.h>
#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    const int cheight = 800;
    const int cwidth = 1200;
    const int groundHeight = cheight - 40;

    float lineAngle;
    float length = 100;
    float gravity = 1;
    float velocity = 3;
    float veloX, veloY;
    float distanceX, distanceY = 0;
    float hmax;

    int originX = groundHeight;
    int time = 0;
    int timeY = 0;
    int i = 0;

    bool fired = false;
    bool collided = false;
    bool reachMax = false;
    bool allowFire = true;

    initwindow(cwidth, cheight);

    while (true)
    {
        //Draw red aim
        setcolor(4);
        circle(mousex(), mousey(), 10);
        line(mousex()-10, mousey(), mousex()+10, mousey());
        line(mousex(), mousey()-10, mousex(), mousey()+10);
        //Draw ground
        setcolor(15);
        line(0, groundHeight, cwidth, groundHeight);
        rectangle(600, 650, 650, groundHeight);
        //Calculate cursor angle from ground
        lineAngle = atan((groundHeight - (float)mousey()) / (float)mousex());

        float lenX = length * cos(lineAngle);
        float lenY = groundHeight - (length * sin(lineAngle));
        if(lineAngle>0){
            line(0, groundHeight, lenX, lenY);
        } else{
            line(0, groundHeight, length, groundHeight);
        }

        if (ismouseclick(WM_LBUTTONDOWN))
        {
            if (allowFire){
                fired = true;
                veloX = velocity * cos(lineAngle) * 10;
                veloY = velocity * sin(lineAngle) * 10;
                hmax = groundHeight - (((veloY*veloY)/(2*gravity))*100);
                time = 0;
                timeY = 0;
                reachMax = false;
                collided = false;
                allowFire = false;
                distanceX = 0;
                distanceY = groundHeight;
                //cout << "CLICKED" << endl;
            }
            clearmouseclick(WM_LBUTTONDOWN);
        }
        if (fired && !collided)
        {
            //cout << "fired" << endl;
            distanceX = veloX * time;
            if (distanceY>hmax && !reachMax){
                distanceY = (groundHeight - 10) - (((veloY * time) - (0.5 * gravity * time * time)));
            } else {
                reachMax = true;

                distanceY = (groundHeight - 10) + (0.5 * gravity * timeY * timeY);
                timeY++;
            }
            circle(distanceX, distanceY, 10);
        }

        if (distanceY > groundHeight){
                //cout << "BOOMMM" << endl;
                collided = true;
                fired = false;
                distanceY = groundHeight;
        }
        if (collided){
            if (i<=100){
                setcolor(14);
                circle(distanceX, distanceY, i);
                //cout << collided << endl;
            } else if (i>=100){
                collided = false;
                allowFire = true;
                i = 0;
            }
            i++;
        }
        time++;
        delay(10);
        cleardevice();
    }
}

