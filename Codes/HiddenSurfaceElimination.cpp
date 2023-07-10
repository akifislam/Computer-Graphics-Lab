#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void Triangle()
{
    int x[] = {10, 50, 100};
    int y[] = {100, 20, 100};
    
    setcolor(YELLOW);

    for (int i = 0; i < 3; i++)
    {
        line(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3]);
    }
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(50, 25, YELLOW);
}

void Circle()
{
    setcolor(RED);
    circle(100, 100, 45);
    setfillstyle(SOLID_FILL, RED);
    floodfill(101, 101, RED);
}

void Rectangle()
{
    setcolor(GREEN);
    rectangle(100-20, 100-20, 180, 180);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(101, 101, GREEN);
}

int main()
{
    string sequence;
    cin >> sequence;
	int gd = DETECT;
	int gm = DETECT;
	initgraph(&gd, &gm, "");
    
    for (int i = 0; i < sequence.size(); i++)
    {
        if(sequence[i]=='C')
            Circle();
        else if(sequence[i]=='R')
            Rectangle();
        else
            Triangle();
    }
    

    getch();
    return 0;
}