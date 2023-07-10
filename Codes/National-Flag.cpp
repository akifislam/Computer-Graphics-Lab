#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main(){
    int gd = DETECT;
    int gm = DETECT;

    initgraph(&gd,&gm,"");

    // Setting Rectangle Parameter by maintaining width:height = 10:6 ratio
    int scale_factor = 30;

    int x1;
    int y1;
    cout<<"Enter the start point of the flag (x1,y1):";
    cin>>x1;
    cin>>y1;

    int x2 = x1+10*scale_factor;
    int y2 = y1+6*scale_factor;

    // Drawing Rectangle
    setcolor(GREEN);
    setfillstyle(SOLID_FILL,GREEN);
    rectangle(x1,y1,x2,y2);
    floodfill(x1+1,y1+1,GREEN);

    //Drawing Circle
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    circle(x1+(x2-x1)*0.45,y1+(y2-y1)*0.5, 2*scale_factor);
    floodfill(x1+(x2-x1)*0.45+1,y1+(y2-y1)*0.5+1,RED);

    //Drawing a Handle
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    rectangle(x1-max(scale_factor/3,10),y1,x1,y2*2);

    getch();

}
/*
    AKIF ISLAM
    1910776135
*/
