
# Computer Graphics Lab

This repository contains my Computer Graphics Lab Finals experiments and code.

# Topic Covered
- Draw the National Flag of Bangladesh

# Experiment 01 - Draw the National Flag of Bangladesh

```c++
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
```
### Input 
![National Flag Input](./Inputs/National-Flag-Input.png)

### Output
![National Flag Output](./Outputs/National-Flag-Output.png)

# Experiment 02 - Simulate Two Dimensional Geometric Translation, Rotation & Scaling

## Translation
```c++
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

    //Taking Translation Factor
    cout<<"Enter Translation Factor (Tx,Ty) :";
    int tx,ty;
    cin>>tx>>ty;
    
    draw_polygon(coordinates,7);
    
    //Translate all points
    for (int i = 0; i < coordinates.size(); i++)
    {
        coordinates[i].first+=tx;
        coordinates[i].second+=ty;
    }

    draw_polygon(coordinates,2);
    getch();

}
```
### Input 
![](./Inputs/Translation-Input.png)

### Output
![](./Outputs/Translation-Output.png)


## Rotation
```c++
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
```
### Input 
![](./Inputs/Rotation-Input.png)

### Output
![](./Outputs/Rotation-Output.png)


## Scaling
```c++
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
```
### Input 
![](./Inputs/Scaling-Input.png)

### Output
![](./Outputs/Scaling-Output.png)

