#include <graphics.h>
#include <iostream>
using namespace std;

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3,int x4, int y4, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3,x4,y4 );
    line(x4, y4, x1, y1);
}


int main() {
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2, x3, y3,x4,y4;
    float Sx, Sy;

    initgraph(&gdriver, &gmode, "C:\\\\Tc\\\\BGI");

    // Input vertices
    cout << "Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3>>x4>>y4;

    // Draw original triangle
    drawRectangle(x1, y1, x2, y2, x3, y3,x4,y4,WHITE);

    // Input scaling factors
    cout << "Enter scaling factors (Sx Sy): ";
    cin >> Sx >> Sy;

    // Calculate centroid
    int cx = (x1 + x2 + x3+x4) / 4;
    int cy = (y1 + y2 + y3+y4) / 4;

    // Scale vertices
    int x1_scaled = cx + (x1 - cx) * Sx;
    int y1_scaled = cy + (y1 - cy) * Sy;
    int x2_scaled = cx + (x2 - cx) * Sx;
    int y2_scaled = cy + (y2 - cy) * Sy;
    int x3_scaled = cx + (x3 - cx) * Sx;
    int y3_scaled = cy + (y3 - cy) * Sy;
    int x4_scaled = cx + (x4- cx) * Sx;
    int y4_scaled = cy + (y4 - cy) * Sy;

    // Draw scaled triangle
    drawRectangle(x1_scaled, y1_scaled, x2_scaled, y2_scaled, x3_scaled, y3_scaled,x4_scaled,y4_scaled ,YELLOW);

    getch();
    closegraph();
    return 0;
}

