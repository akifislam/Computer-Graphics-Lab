#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main(){
    int gd = DETECT;
    int gm = DETECT;
    initgraph(&gd,&gm," ");

    cout<<"Enter (x1,y1):";
    int x1,y1;
    cin>>x1>>y1;

    cout<<"Enter (x2,y2):";
    int x2,y2;
    cin>>x2>>y2;

    int dx = x2-x1;
    int dy = y2-y1;

    int cur_x = x1;
    int cur_y = y1;
    outtextxy(cur_x,cur_y,"X1,Y1");
    putpixel(cur_x,cur_y,14);
    int P = 2*dy-dx;
    
    while(cur_x<x2 || cur_y<y2){    
        if(P<0){
            cur_x++;
            putpixel(cur_x,cur_y,14);
            P+=2*dy;
        }
        else{
            cur_x++;
            cur_y++;
            putpixel(cur_x,cur_y,14);
            P+=2*dy-2*dx;
        }


    }
    outtextxy(cur_x,cur_y,"X2,Y2");
    getch();
    
}