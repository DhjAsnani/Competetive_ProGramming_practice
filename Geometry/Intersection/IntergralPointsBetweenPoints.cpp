#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,b%a);
}
struct point{
	int x,y;
};
int numOfPoints(point a,point b)
{
	if(a.x == b.x)
		return abs(a.y-b.y) - 1;
	if(a.y == b.y)
		return abs(a.x-b.x) - 1;
	else return gcd(abs(a.x-b.x),abs(b.y-a.y)) - 1;
}
int main()
{
	point p1 = {1,9},p2 = {8,16};
	cout<<"Intergal Points "<<numOfPoints(p1,p2);
}
