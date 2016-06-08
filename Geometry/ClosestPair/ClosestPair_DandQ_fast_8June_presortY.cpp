#include<bits/stdc++.h>
using namespace std;
struct Point
{
	int x,y;
};
int compareY(const void* a,const void* b)
{
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y-p2->y);
}
int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}
float dist(Point p1, Point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
//for finding min length
float bruteForce (Point P[],int n)
{
	float min  = FLT_MAX;
	for (int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(dist(P[i],P[j])<min)
			{
				min = dist(P[i],P[j]);
			}
		}
	}
	return min;
}
float min(float x,float y)
{
	return (x<y)?x:y;
}

float stripClosest (Point strip[], int size, float d)
{
	float min = d;
//	qsort(strip,size, sizeof(Point), compareY);
	for (int i=0;i<size;i++)
	{
		for (int j = i+1; j<size && (strip[j].y-strip[i].y)<min;j++)
		{
			if(dist(strip[i],strip[j])<min)
			{
				min = dist(strip[i],strip[j]);
			}
		}
	}
	
	return min;
}
float closestUtil (Point P[],int n)
{
	if(n<=3)
	{
		return bruteForce(P,n);	
	}
	int mid = n/2;
	Point midPoint = P[mid];
	float dl = closestUtil(P,mid);
	float dr = closestUtil(P+mid, n - mid);
	
	float d = min(dl,dr);
	
	Point strip[n];
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(abs(P[i].x - midPoint.x)<d)
			strip[j] = P[i],j++;
	}
	return min(d, stripClosest(strip,j,d));
}
float closest(Point P[],int n)
{
	// presort points according to X and Y axis
	qsort(P, n, sizeof(Point), compareX);
	qsort(P, n, sizeof(Point), compareY);
	return closestUtil(P,n);
}
int main()
{
	Point point[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = sizeof(point)/sizeof(point[0]);
	cout<<"Smallest distance "<<closest(point , n);
}




























