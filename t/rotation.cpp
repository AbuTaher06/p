#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3,int x4,int y4, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4,x1, y1);

}

int main() {
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2, x3, y3;
    float angle;

    initgraph(&gdriver, &gmode, "C:\\\\Tc\\\\BGI");
    while(1){
cout<<"Choose an Option for Scaled:";
cout<<"\n 2.Traingle\n 3.Rectangle\n 4.Exit";
cout<<"\nChoice Your option:";
int choice;
cin>>choice;

if(choice==2){
        cleardevice();

    // Input vertices of the triangle
    cout << "Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Draw the original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Input rotation angle
    cout << "Enter the rotation angle (in degrees): ";
    cin >> angle;

    // Convert angle to radians
    float radian = angle * (M_PI / 180.0);

    // Calculate centroid of the triangle
    int cx = (x1 + x2 + x3) / 3;
    int cy = (y1 + y2 + y3) / 3;

    // Rotate vertices around the centroid
    int x1_rot = cx + (x1 - cx) * cos(radian) - (y1 - cy) * sin(radian);
    int y1_rot = cy + (x1 - cx) * sin(radian) + (y1 - cy) * cos(radian);

    int x2_rot = cx + (x2 - cx) * cos(radian) - (y2 - cy) * sin(radian);
    int y2_rot = cy + (x2 - cx) * sin(radian) + (y2 - cy) * cos(radian);

    int x3_rot = cx + (x3 - cx) * cos(radian) - (y3 - cy) * sin(radian);
    int y3_rot = cy + (x3 - cx) * sin(radian) + (y3 - cy) * cos(radian);

    // Draw rotated triangle
    drawTriangle(x1_rot, y1_rot, x2_rot, y2_rot, x3_rot, y3_rot, YELLOW);
}

    else if(choice==3){
    cleardevice();
    int x1, y1, x2, y2, x3, y3,x4,y4;
    float angle;

    initgraph(&gdriver, &gmode, "C:\\\\Tc\\\\BGI");

    // Input vertices of the triangle
    cout << "Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3>>x4>>y4;

    // Draw the original triangle
    drawRectangle(x1, y1, x2, y2, x3, y3,x4,y4,WHITE);

    // Input rotation angle
    cout << "Enter the rotation angle (in degrees): ";
    cin >> angle;

    // Convert angle to radians
    float radian = angle * (M_PI / 180.0);

    // Calculate centroid of the triangle
    int cx = (x1 + x2 + x3+x4) / 4;
    int cy = (y1 + y2 + y3+x4) / 4;

    // Rotate vertices around the centroid
    int x1_rot = cx + (x1 - cx) * cos(radian) - (y1 - cy) * sin(radian);
    int y1_rot = cy + (x1 - cx) * sin(radian) + (y1 - cy) * cos(radian);

    int x2_rot = cx + (x2 - cx) * cos(radian) - (y2 - cy) * sin(radian);
    int y2_rot = cy + (x2 - cx) * sin(radian) + (y2 - cy) * cos(radian);

    int x3_rot = cx + (x3 - cx) * cos(radian) - (y3 - cy) * sin(radian);
    int y3_rot = cy + (x3 - cx) * sin(radian) + (y3 - cy) * cos(radian);

    int x4_rot = cx + (x4 - cx) * cos(radian) - (y4 - cy) * sin(radian);
    int y4_rot = cy + (x4- cx) * sin(radian) + (y4 - cy) * cos(radian);

    // Draw rotated triangle
    drawRectangle(x1_rot, y1_rot, x2_rot, y2_rot, x3_rot, y3_rot,x4_rot,y4_rot ,YELLOW);

    }
    else if(choice==4){
        exit(0);
    }
    else {
        cout<<"Invalid";
    }
}
    getch();
    closegraph();
    return 0;
}

