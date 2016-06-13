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
int main()
{
	vector<point> points;
	points.push_back({0,0});
	points.push_back({4,0});
	points.push_back({2,4});
	//points.push_back({0,4});
	cout<<area(points);
}
