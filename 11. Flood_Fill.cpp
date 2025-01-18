#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void floodFill(int x, int y, int oldColor, int newColor)
{
    if(getpixel(x, y) == oldColor)
    {
        putpixel(x, y, newColor);
        delay(10);
        floodFill(x+1, y, oldColor, newColor);
        floodFill(x, y+1, oldColor, newColor);
        floodFill(x-1, y, oldColor, newColor);
        floodFill(x, y-1, oldColor, newColor);
        //delay(100);
    }
}

int main()
{
    int h, k, r;
    cout << "Enter the Coordinates of the Circle's Center (h,k): ";
    cin >> h >> k;
    cout << "Enter the radius of the Circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    circle(h, k, r);

    floodFill(h, k, BLACK, MAGENTA);

    getch();
    closegraph();

    return 0;
}
