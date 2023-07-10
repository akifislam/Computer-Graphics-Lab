#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void draw_polygon(vector<pair<int,int>> poly,int color){
    
    setcolor(color);    

    for (int i = 0; i < poly.size(); i++)
        line(poly[i].first,poly[i].second,poly[(i+1)%poly.size()].first,poly[(i+1)%poly.size()].second);

}

int main(){

    int gd = DETECT;
    int gm = DETECT;

    initgraph(&gd,&gm,"");

    // Taking No of Sides of a Polygon
    cout<<"Enter No of  Side : ";
    int no_of_side;
    cin>>no_of_side;

    // Taking co-ordinates of the sides
    vector<pair<int,int>> coordinates;
    
    for (int i = 0; i < no_of_side; i++)
    {   
        int x,y;
        cout<<"Enter (X"<<i+1<<",Y"<<i+1<<"):";
        cin>>x>>y;
        coordinates.push_back({x,y});

    }

    //Taking Scaling Factor
    cout<<"Enter Scaling Factor (Sx,Sy) :";
    int sx,sy;
    cin>>sx>>sy;
    
    draw_polygon(coordinates,7);
    //Translate all points
    for (int i = 0; i < coordinates.size(); i++)
    {
        coordinates[i].first*=sx;
        coordinates[i].second*=sy;
    }

    draw_polygon(coordinates,14);
    getch();

}