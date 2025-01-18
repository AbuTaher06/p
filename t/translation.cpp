#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void translateCircle(int x,int y,int r,float tx,float ty){

setcolor(WHITE);
circle(x,y,r);

setcolor(YELLOW);
circle(x+tx,y+ty,r);
}

void  translateRectangle(int x,int y,float tx, float ty){

setcolor(WHITE);
rectangle(x,y,x+100,y+50);

setcolor(YELLOW);
rectangle(x+tx,y+ty,x+100+tx,y+50+ty);
}

void  translatetangle(int x1,int y1,int x2,int y2,int x3,int y3,float tx, float ty){

setcolor(WHITE);
line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x1,y1);



setcolor(YELLOW);
line(x1+tx,y1+ty,x2+tx,y2+ty);
line(x2+tx,y2+ty,x3+tx,y3+ty);
line(x3+tx,y3+ty,x1+tx,y1+ty);

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
        int h,k,r;
float tx,ty;

    cout<<"Enter The circle Coordinates:";
    cin>>h>>k;
    cout<<"Enter The circle radius:";
    cin>>r;
    cout<<"Enter Scaled Factor(Tx,Ty):";
    cin>>tx>>ty;
    translateCircle(h,k,r,tx,ty);
}
else if(choice==2){
        int x,y;
float tx,ty;

    cout<<"Enter The Top right point(x,y):";
    cin>>x>>y;
    cout<<"Enter Scaled Factor(tx,ty):";
    cin>>tx>>ty;
     translateRectangle(x,y,tx,ty);
}
else if(choice==3){
        int x1,y1,x2,y2,x3,y3;
float tx,ty;

    cout<<"Enter The point(x1,y1):";
    cin>>x1>>y1;
    cout<<"Enter The point(x2,y2):";
    cin>>x2>>y2;
    cout<<"Enter The point(x3,y3):";
    cin>>x3>>y3;
    cout<<"Enter Scaled Factor(Tx,Ty):";
    cin>>tx>>ty;
     translatetangle(x1,y1,x2,y2,x3,y3,tx,ty);
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
