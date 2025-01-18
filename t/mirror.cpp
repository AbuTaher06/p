#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>

using namespace std;

const float PI = 3.14159;

void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void drawCircle(int x, int y, int radius) {
    circle(x, y, radius);
}

void rotatePoint(int &x, int &y, int cx, int cy, float angle) {
    float radian = angle * PI / 180.0;
    int tempX = x, tempY = y;
    x = cx + (tempX - cx) * cos(radian) - (tempY - cy) * sin(radian);
    y = cy + (tempX - cx) * sin(radian) + (tempY - cy) * cos(radian);
}

void rotateTriangle(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int cx, int cy, float angle) {
    rotatePoint(x1, y1, cx, cy, angle);
    rotatePoint(x2, y2, cx, cy, angle);
    rotatePoint(x3, y3, cx, cy, angle);
    drawTriangle(x1, y1, x2, y2, x3, y3);
}

void rotateRectangle(int &x1, int &y1, int &x2, int &y2, int cx, int cy, float angle) {
    int x3 = x2, y3 = y1;
    int x4 = x1, y4 = y2;

    rotatePoint(x1, y1, cx, cy, angle);
    rotatePoint(x2, y2, cx, cy, angle);
    rotatePoint(x3, y3, cx, cy, angle);
    rotatePoint(x4, y4, cx, cy, angle);

    line(x1, y1, x3, y3);
    line(x3, y3, x2, y2);
    line(x2, y2, x4, y4);
    line(x4, y4, x1, y1);
}

void rotateCircle(int x, int y, int radius, float angle) {
    // A circle remains unchanged under rotation, redraw it
    circle(x, y, radius);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (true) {
        cleardevice();
        xx:
        cout << "1. Rotate Triangle\n";
        cout << "2. Rotate Rectangle\n";
        cout << "3. Rotate Circle\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 4) {
            break;
        }

        cleardevice();

        switch (choice) {
            case 1: {
                int x1 = 100, y1 = 100, x2 = 150, y2 = 50, x3 = 200, y3 = 100;
                int cx = (x1 + x2 + x3) / 3;
                int cy = (y1 + y2 + y3) / 3;
                float angle;
                drawTriangle(x1, y1, x2, y2, x3, y3);
                cout << "Enter rotation angle (in degrees): ";
                cin >> angle;
                cleardevice();
                rotateTriangle(x1, y1, x2, y2, x3, y3, cx, cy, angle);
                break;
            }
            case 2: {
                int x1 = 100, y1 = 100, x2 = 200, y2 = 150;
                int cx = (x1 + x2) / 2;
                int cy = (y1 + y2) / 2;
                float angle;
                drawRectangle(x1, y1, x2, y2);
                cout << "Enter rotation angle (in degrees): ";
                cin >> angle;
                cleardevice();
                rotateRectangle(x1, y1, x2, y2, cx, cy, angle);
                break;
            }
            case 3: {
                int x = 150, y = 150, radius = 50;
                float angle;
                drawCircle(x, y, radius);
                cout << "Enter rotation angle (in degrees): ";
                cin >> angle;
                cleardevice();
                rotateCircle(x, y, radius, angle);
                break;
            }
            default:
                cout << "Invalid choice!\n";
                break;
        }

        goto xx;
    }

    closegraph();
    return 0;
}
