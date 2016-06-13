#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
int area( vector<point> points)
{
	int n = points.size();
	points.push_back(points[0]);
	int up=0,down=0;
	for(int i=0;i<n;i++)
	{
		up+=points[i].x*points[i+1].y;
		down+=points[i].y*points[i+1].x;
	}
	return 0.5*abs(up + down);
}
int gcd(int a, int b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}
int getBoundaryCount(point p,point q)
{
    // Check if line parallel to axes
    if (p.x==q.x)
        return abs(p.y - q.y) - 1;
    if (p.y == q.y)
        return abs(p.x-q.x) - 1;
 
    return gcd(abs(p.x-q.x),abs(p.y-q.y))-1;
}

int main()
{
	vector<point> points;
	points.push_back({0,0});
	points.push_back({0,5});
	points.push_back({5,0});
	int boundaryC = getBoundaryCount(points[0],points[1])+getBoundaryCount(points[1],points[2])+getBoundaryCount(points[2],points[0])+3;
	int ans = 	area(points);
	ans = ans + 1 - boundaryC/2 ;
	cout<<ans<<endl;
		
}
