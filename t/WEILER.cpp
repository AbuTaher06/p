#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main(){

int gd=DETECT,gm;
initgraph(&gd, &gm,(char*)"");
int wx1,wx2,wx3,wx4;
cout<<"Enter The top bottom:";
cin>>wx1>>wx2;
cout<<"Enter The Left Right point:";
cin>>wx3>>wx4;
rectangle(wx1,wx2,wx3,wx4);

//int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
//cout<<"Enter the value of coordinates of polygon:";
//cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5;

//line(x1,y1,x2,y2);
//line(x2,y2,x3,y3);
//line(x3,y3,x4,y4);
//line(x4,y4,x5,y5);
//line(x5,y5,x1,y1);
line(120,250,120,50);
line(120,50,180,200);                   // line দিয়ে একটা shape draw করলাম, যেইটা rectangle-এর বাইরেও যায়
line(180,200,280,50);
line(280,50,280,250);
line(280,250,120,250);


int x,y;
cout<<"Enter The starting point:";
cin>>x>>y;

putpixel(x,y,YELLOW);

outtextxy(x+10,y,(char*)"Start");
y=y-1;

while(1){

    putpixel(x,y,YELLOW);

    if(getpixel(x-1,y+1)==WHITE){
        y=y+1;
        x=x-1;
    }
 else if(getpixel(x,y+1)==WHITE){
        y=y+1;
    }
    else if(getpixel(x+1,y+1)==WHITE){
        x=x+1;
        y=y+1;
    }
    else if(getpixel(x+1,y)==WHITE){
        x=x+1;

    }
   else if(getpixel(x+1,y-1)==WHITE){
        x=x+1;
        y=y-1;
    }
   else if(getpixel(x,y-1)==WHITE){
        y=y-1;
    }
    else if(getpixel(x,y-2)==WHITE){
        y=y-2;
    }
    else if(getpixel(x-1,y) == WHITE)
        {
            x=x-1;
           // y=y-1;
        }
    else if(getpixel(x-1,y-1)==WHITE){
        x=x-1;
        y=y-1;

    }

    else if(getpixel(x-2,y)==WHITE){
       x=x-2;
    }
    else break;
    delay(5);

}

outtextxy(x+20,y+30,(char*)"End");
getch();
}
