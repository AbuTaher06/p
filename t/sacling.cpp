#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void scaledCircle(int x,int y,int r,float sr){

setcolor(WHITE);
circle(x,y,r);

setcolor(YELLOW);
circle(x,y,r*sr);
}

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3,int x4, int y4, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3,x4,y4 );
    line(x4, y4, x1, y1);

}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}


int main(){

int gd=DETECT, gm;
initgraph(&gd, &gm, (char*)"");

while(1){
cout<<"Choose an Option for Scaled:";
cout<<"\n 1.Circle\n 2.Rectangle\n 3.Traingle\n 4.Exit";
cout<<"\nChoice Your option:";
int choice;
cin>>choice;

if(choice==1){
        cleardevice();
        int h,k,r;
float sr;

    cout<<"Enter The circle Coordinates:";
    cin>>h>>k;
    cout<<"Enter The circle radius:";
    cin>>r;
    cout<<"Enter Scaled Factor(Sr):";
    cin>>sr;
    scaledCircle(h,k,r,sr);
}
else if(choice==2){
     cleardevice();
        int x1,y1,x2,y2,x3,y3,x4,y4;
float Sx,Sy;

    cout << "Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3>>x4>>y4;

    // Draw original triangle
    drawRectangle(x1, y1, x2, y2, x3, y3,x4,y4,WHITE);
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
    drawRectangle(x1_scaled, y1_scaled, x2_scaled, y2_scaled, x3_scaled, y3_scaled,x4_scaled,y4_scaled ,YELLOW);


}
else if(choice==3){

         cleardevice();
         int x1, y1, x2, y2, x3, y3;
    float Sx, Sy;
       cout << "Enter the vertices of the triangle (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Draw original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE);

    // Input scaling factors
    cout << "Enter scaling factors (Sx Sy): ";
    cin >> Sx >> Sy;

    // Calculate centroid
    int cx = (x1 + x2 + x3) / 3;
    int cy = (y1 + y2 + y3) / 3;

    // Scale vertices
    int x1_scaled = cx + (x1 - cx) * Sx;
    int y1_scaled = cy + (y1 - cy) * Sy;
    int x2_scaled = cx + (x2 - cx) * Sx;
    int y2_scaled = cy + (y2 - cy) * Sy;
    int x3_scaled = cx + (x3 - cx) * Sx;
    int y3_scaled = cy + (y3 - cy) * Sy;

    // Draw scaled triangle
    drawTriangle(x1_scaled, y1_scaled, x2_scaled, y2_scaled, x3_scaled, y3_scaled, YELLOW);
}
else if(choice==4){
    exit(0);
}
else{

cout<<"Invalid Choice";

}
}

getch();
closegraph();
return 0;
}
