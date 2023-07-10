#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

int main()
{

    int gd, gm;
    gd = DETECT, gm = DETECT;
    initgraph(&gd, &gm, "");

    // Input Parameter
    int r = 150;
    int x = 200;
    int y = 200;

    cin>>x>>y>>r;

    // Process
    int P = 1 - r;

    int cur_x = 0, cur_y = r;

    vector<pair<int, int>> points;

    while (cur_x < cur_y)
    {
        points.push_back({cur_x, cur_y});
        points.push_back({cur_y, cur_x});

        cur_x++;

        if (P < 0)
        {
            P += 2 * cur_x + 1;
        }
        else
        {
            cur_y--;
            P += 2 * (cur_x - cur_y) + 1;
        }
    }

    for (int i = 0; i < points.size(); i++)
    {  
        putpixel(x + points[i].first, y + points[i].second, WHITE);
        putpixel(x - points[i].first, y + points[i].second, WHITE);
        putpixel(x - points[i].first, y - points[i].second, WHITE);
        putpixel(x + points[i].first, y - points[i].second, WHITE);

    
    }

    getch();
}