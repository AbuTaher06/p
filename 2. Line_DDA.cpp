#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1, y1, x2, y2, x, y, c = 15;

    cout << "Enter starting coordinates (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter ending coordinates (x2, y2): ";
    cin >> x2 >> y2;

    int h = getmaxy();
    float m= float(y2-y1) / float(x2-x1);
    x = x1;
    y = y1;

    if(m <= 1)
    {
        int step = x2 - x1;
        float y_fl = y;
        for(int k=0; k<=step; k++)
        {
            putpixel(x, h-y, c);
            x++;
            y_fl = y_fl + m;
            y = y_fl;
            delay(20);
        }
    }
    else
    {
        float invSlope = 1 / m;
        int step = y2 - y1;
        float x_fl = x;
        for(int k=0; k<=step; k++)
        {
            putpixel(x, h-y, c);
            y++;
            x_fl = x_fl + invSlope;
            x = x_fl;
            delay(20);
        }
    }

    getch();
    closegraph();

    return 0;
}
