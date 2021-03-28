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

    vector<int> bob{0.0f, 0.0f};
    float len;
    vector<int> origin{300, 0};

    float gravity = 1;

    initwindow(600, 800);

    angle = PI / 4;
    len = 200;

    while (true)
    {
        float force = gravity * sin(angle);
        angleA = (-1 * force) / len;
        angleV += angleA;
        angle += angleV;

        bob[0] = len * sin(angle) + origin[0];
        bob[1] = len * cos(angle) + origin[1];

        line(origin[0], origin[1], bob[0], bob[1]);

        getch();

        closegraph();
    }
}
