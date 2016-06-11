#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
bool doOverlap(point p1,point p2,point p3,point p4)
{
	if(p2.x>p3.x&&p2.y>p3.y)
		return true;
	return false;
}
int main()
{point l1 = {4, 4}, r1 = {10, 10};
    point l2 = {5, 5}, r2 = {6,6};
    if (doOverlap(l2, r2,l1, r1 ))
        printf("Rectangles Overlap");
    else
        printf("Rectangles Don't Overlap");
    return 0;
	
}
