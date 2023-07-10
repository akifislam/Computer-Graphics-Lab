#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

double to_radian(int degree){
    return (degree*3.1416)/180;
}

void draw_polygon(vector<pair<int,int>> poly,int color){
    
    setcolor(color);    

    for (int i = 0; i < poly.size(); i++)
        line(poly[i].first,poly[i].second,poly[(i+1)%poly.size()].first,poly[(i+1)%poly.size()].second);

}

int main(){
    
    int gd = DETECT;
    int gm = DETECT;

    initgraph(&gd,&gm,"C:\\Users");

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

        
    cout<<"Rotation Angle in Degree : ";
    int angle;
    cin>>angle;
    
    //Taking Scaling Factor
    cout<<"Enter Pivot Point for Rotation (rx,ry) :";
    int rx,ry;
    cin>>rx>>ry;


    draw_polygon(coordinates,14);
 
    //Translate to Origin, Then Rotate, Then Back to Pivot Point
    for (int i = 0; i < coordinates.size(); i++)
    {
        double x = coordinates[i].first;
        double y = coordinates[i].second;
        
        //Move to Origin
        int x_shift=x-rx;
        int y_shift=y-ry;
    
        //Rotate
        x = x_shift*cos(to_radian(angle))-y_shift*sin(to_radian(angle));
        y = x_shift*sin(to_radian(angle))+y_shift*cos(to_radian(angle));

        //Back to Pivot Point
        x+=rx;
        y+=ry;

        coordinates[i].first = x;
        coordinates[i].second = y;   
    }

    draw_polygon(coordinates,2);
    getch();

}