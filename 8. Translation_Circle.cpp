#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void translate_circle(int h, int k, int x, int y, int r)
{
    int height = getmaxy();

    cleardevice();
    circle(x, height-y, r);
    circle(h, height-k, r);
    line(x, height-y, h, height-k);
    delay(20);
}

int main()
{
    int h, k, x, y, r, tx, ty;
    cout << "Enter the Coordinates of the Circle's Center (h,k): ";
    cin >> h >> k;
    cout << "Enter the radius of the Circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int height = getmaxy();

    circle(h, height-k, r);

    cout << "Enter Translation Value of the Circle (tx,ty): ";
    cin >> tx >> ty;

    x = h;
    y = k;

    for(x=h; x<=h+tx; x++)
    {
        translate_circle(h, k, x, y, r);
    }

    for(y=k; y<=k+ty; y++)
    {
        translate_circle(h, k, x, y, r);
    }

    getch();
    closegraph();

    return 0;
}


