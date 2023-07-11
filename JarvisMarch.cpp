#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

int orientation(Point p1, Point p2, Point p3)
{
    int val = (p3.y - p2.y) * (p2.x - p1.x) - (p2.y - p1.y) * (p3.x - p2.x);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

void convexHull(Point points[], int n)
{
    if (n < 3)
    {
        return;
    }
    vector<Point> hull;

    int on_hull = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[on_hull].x)
        {
            on_hull = i;
        }
    }

    do
    {
        hull.push_back(points[on_hull]);
        int next_point = (on_hull+1)%n;
        for (int p = 0; p < n; p++)
        {
            if (orientation(points[on_hull], points[next_point], points[p]) == 2)
                next_point = p;
        }
        on_hull = next_point;

    } while (on_hull != 0);

    for (int i = 0; i < hull.size(); i++)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }
}

int main()
{
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
