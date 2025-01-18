#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int h, k, a, b, x, y, r;
    float pi = 3.1416, th = 0, theta, d_th = pi / 180;

    cout << "Enter the Coordinates of the Circle's Center (h, k): ";
    cin >> h >> k;

    cout << "Enter the radius of the circle: ";
    cin >> r;

    int height = getmaxy();

    circle(h, height-k, r);

    cout << "Enter the Coordinates of the point (a, b): ";
    cin >> a >> b;

    putpixel(a, height-b, 15);

    outtextxy(a+10, height-b, (char*)"P");

    cout << "Enter the rotation angle (theta): ";
    cin >> theta;

    theta = theta * pi / 180;

    x = h;
    y = k;

    while(th <= theta){

        cleardevice();

        circle(x, height-y, r);
        circle(h, height-k, r);
        line(x, height-y, a, height-b);
        line(h, height-k, a, height-b);
        putpixel(a, height-b, 15);
        outtextxy(a+10, height-b, (char*)"P");
        delay(20);

        th = th + d_th;

        x = h*cos(th) - k*sin(th) - (a*cos(th) - b*sin(th) - a);
        y = h*sin(th) + k*cos(th) - (a*sin(th) + b*cos(th) - b);
    }

    getch();
    closegraph();

    return 0;
}
