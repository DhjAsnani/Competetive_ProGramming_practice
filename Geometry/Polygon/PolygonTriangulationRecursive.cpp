#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000.0
struct point
{
	int x,y;
};
double min (double x,double y)
{
	return (x<=y)?x:y;
}
double dist(point p1,point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) +(p1.y - p2.y)*(p1.y - p2.y));
}
double cost(point points[],int i,int j,int k)
{
	return dist(points[i],points[j]) + dist(points[j],points[k]) + dist(points[k],points[i]);
}
double mTC(point points[] ,int i,int j)
{
	if(j<i+2) return 0;
	double res = MAX;
	for(int k=i+1;k<j;k++)
	{
		res = min(res,mTC(points,i,k)+mTC(points,k,j) + cost(points,i,k,j) );
	}
	return res;
}
int main()
{
    point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    int n = sizeof(points)/sizeof(points[0]);
    cout << mTC(points, 0, n-1);
    return 0;
}
