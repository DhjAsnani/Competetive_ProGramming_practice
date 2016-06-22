#include<bits/stdc++.h>
using namespace std;
long lookup[105][105];
int minmax(int A[],int s,int e)
{
if(s==e)
	return A[s];
if(s+1==e)
	return max(A[s],A[e]);
if(lookup[s][e]==0)
	{
		lookup[s][e] = max(A[s] + min(minmax(A,s+1,e-1),minmax(A,s+2,e)),A[e] + min(minmax(A,s+1,e-1),minmax(A,s,e-2)));
	}
return lookup[s][e];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	memset(lookup, 0, sizeof(lookup));
	int n;
	cin>>n;
	int A[n] ;
	for(int i=0;i<n;i++)cin>>A[i];
	cout<<minmax(A,0,n-1)<<endl;
}
}
