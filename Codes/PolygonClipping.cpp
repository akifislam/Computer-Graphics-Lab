#include<iostream>
#include<graphics.h>
#include<fstream>
#include<vector>

using namespace std;

class Point{
    public:
        int x, y;

        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
};

Point intersect_point(Point p1, Point p2, 
                Point p3, Point p4)
{
    int xnum = (p1.x*p2.y - p1.y*p2.x) * (p3.x-p4.x) -
              (p1.x-p2.x) * (p3.x*p4.y - p3.y*p4.x);
    int xden = (p1.x-p2.x) * (p3.y-p4.y) - (p1.y-p2.y) * (p3.x-p4.x);

    int ynum = (p1.x*p2.y - p1.y*p2.x) * (p3.y-p4.y) -
              (p1.y-p2.y) * (p3.x*p4.y - p3.y*p4.x);
    int yden = (p1.x-p2.x) * (p3.y-p4.y) - (p1.y-p2.y) * (p3.x-p4.x);

    return Point(xnum/xden, ynum/yden);
}

vector<Point> clip(vector<Point> points, Point p1, Point p2)
{
    vector<Point> new_points;

    for(int i = 0; i < points.size(); i++)
    {
        int k = (i+1) % points.size();
        int ix = points[i].x;
        int iy = points[i].y;
        int kx = points[k].x;
        int ky = points[k].y;

        int i_pos = (p2.x - p1.x) * (iy - p1.y) - (p2.y - p1.y) * (ix - p1.x);

        int k_pos = (p2.x - p1.x) * (ky - p1.y) - (p2.y - p1.y) * (kx - p1.x);

        // Case 1 : When both points are inside
        if(i_pos < 0 && k_pos < 0)
        {
            new_points.push_back(Point(kx, ky));
        }

        // Case 2: When only first point is outside
        else if(i_pos >= 0 && k_pos < 0)
        {
            new_points.push_back(intersect_point(p1, p2, Point(ix, iy), Point(kx, ky)));

            new_points.push_back(Point(kx, ky));
        }
        
        // Case 3: When only second point is outside
        else if(i_pos < 0 && k_pos >= 0)
        {
            new_points.push_back(intersect_point(p1, p2, Point(ix, iy), Point(kx, ky)));
        }

        else 
        {
            // No points are added.
        }
    }


    return new_points;


}

vector<Point> southHodgeClip(vector<Point> points, vector<Point> clipper)
{
    for(int i = 0; i < clipper.size(); i++)
    {
        int k = (i+1) % clipper.size();

        points = clip(points, clipper[i], clipper[k]);

    }
    for(int i = 0; i < points.size(); i++)
    {
        cout<<points[i].x<<" "<<points[i].y<<endl;
    }
    return points;
}


void draw(vector<Point> points)
{
    points.push_back(points[0]);
    int n = points.size();
    int arr[ 2*n ];
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        arr[j] = points[i].x;
        arr[j+1] = points[i].y;
        j += 2;
    }
    drawpoly(n, arr);
}

int main(int argc, char const *argv[])
{
    int gd = DETECT;
    int gm;
    
    vector<Point> clipper;
    clipper.push_back(Point(150, 150));
    clipper.push_back(Point(150, 200));
    clipper.push_back(Point(200, 200));
    clipper.push_back(Point(200, 150));

    initgraph(&gd, &gm, NULL);
    
    draw(clipper);
    
    int n;
    
    {
        ifstream cin("input.txt");
        cin>>n;
    }
    vector<Point> points;
    {
        ifstream cin("input.txt");
        cin>>n;
        int x, y;
        for(int i = 0; i < n; i++)
        {
            cin>>x>>y;
            points.push_back(Point(x, y));
        }
    }

    draw(points);
    getch();
    cleardevice();
    draw(clipper);
    points = southHodgeClip(points, clipper);

    setcolor(GREEN);
    draw(points);

    getch();
    closegraph();
    
    return 0;
}
