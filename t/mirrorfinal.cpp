#include <graphics.h>
#include <iostream>
using namespace std;

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gdriver = DETECT, gmode;
    int x1, y1, x2, y2, x3, y3;

    // Initialize graphics mode
    initgraph(&gdriver, &gmode, "C:\\\\Tc\\\\BGI");

    // Input vertices of the triangle
    cout << "Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;


    // Draw the original triangle in white
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);
    while(1){

    cout << "Choose an Option for Scaled:";
        cout << "\n 1. X_Axix Mirroring\n 2.Y_Axix Mirroring\n3.Exit";
        cout << "\nChoice Your option: ";
        int choice;
cin >> choice;


    // Perform mirroring about the x-axis
    if(choice==1){
            cleardevice();
                drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    int x1_x_mirror = x1, y1_x_mirror = -y1;
    int x2_x_mirror = x2, y2_x_mirror = -y2;
    int x3_x_mirror = x3, y3_x_mirror = -y3;

    // Draw x-axis mirrored triangle in yellow
    drawTriangle(x1_x_mirror, y1_x_mirror + getmaxy() / 2,
                 x2_x_mirror, y2_x_mirror + getmaxy() / 2,
                 x3_x_mirror, y3_x_mirror + getmaxy() / 2,
                 YELLOW);
    }
    else if(choice==2){
            cleardevice();
                drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);


    // Perform mirroring about the y-axis
    int x1_y_mirror = -x1, y1_y_mirror = y1;
    int x2_y_mirror = -x2, y2_y_mirror = y2;
    int x3_y_mirror = -x3, y3_y_mirror = y3;

    // Draw y-axis mirrored triangle in green
    drawTriangle(x1_y_mirror + getmaxx() / 2, y1_y_mirror,
                 x2_y_mirror + getmaxx() / 2, y2_y_mirror,
                 x3_y_mirror + getmaxx() / 2, y3_y_mirror,
                 GREEN);
    }
 /*else if(choice==3){
        cleardevice();

                        drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Perform mirroring about both x and y axes
    /*int x1_xy_mirror = -x1, y1_xy_mirror = -y1;
    int x2_xy_mirror = -x2, y2_xy_mirror = -y2;
    int x3_xy_mirror = -x3, y3_xy_mirror = -y3;

    // Draw both x and y axes mirrored triangle in red
    drawTriangle(x1_xy_mirror + getmaxx() / 2, y1_xy_mirror + getmaxy() / 2,
                 x2_xy_mirror + getmaxx() / 2, y2_xy_mirror + getmaxy() / 2,
                 x3_xy_mirror + getmaxx() / 2, y3_xy_mirror + getmaxy() / 2,
                 RED);
 }
    // Wait for user input and close graphics*/
    else if(choice==3){
        exit(0);
    }
    else {
            cout << "Invalid choice!";
        }
    }

    getch();
    closegraph();

}



