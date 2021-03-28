#include <graphics.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    float PI = M_PI;
    float angle;

    float angleV = 0.0f;
    float angleA = 0.0f;

    vector<int> bob (2);
    float len;
    vector<int> origin (2);

    float gravity = 1;

    origin.at(0) = 300;
    origin.at(1) = 0;

    bob.at(0) = 0;
    bob.at(0) = 0;

    initwindow(600, 600);

    angle = PI / 2;
    len = 100;
    int trailcount = 0;

    cout << len;
    while (true)
    {
        float force = gravity * sin(angle);
        angleA = (-1 * force) / len;
        angleV += angleA;
        angle += angleV;

        angle *= 0.999;

        bob[0] = len * sin(angle) + origin[0];
        bob[1] = len * cos(angle) + origin[1];

        line(origin[0], origin[1], bob[0], bob[1]);
        circle(bob[0], bob[1], 20);
        circle(mousex(), mousey(), 2);
        delay(10);

        cleardevice();
;    }

    getch();
    // closegraph();
}
