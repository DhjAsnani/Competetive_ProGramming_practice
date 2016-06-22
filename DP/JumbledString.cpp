#include<bits/stdc++.h>
using namespace std;
//long dp[501][501];
int ans(string s,string g)
{
int n = s.length();
int m = g.length();
long dp[m][n];
for(int i=0;i<m;i++)
{
	dp[i][0] = 0;
}
if(s[0]==g[0])
	dp[0][0] = 1;
for(int i=1;i<n;i++)
{
	if(s[i]==g[0])
	{
		dp[0][i] = 1+dp[0][i-1];
	}
	else
	{
		dp[0][i] = dp[0][i-1];
	}
}

for(int i=1;i<m;i++)
{
	for(int j=1;j<n;j++)
	{
		(g[i]==s[j])?dp[i][j] = dp[i][j-1] + dp[i-1][j-1]:dp[i][j] = dp[i][j-1];
		
	}
}
return dp[m-1][n-1];
}	
int main()
{
	int t;
	cin>>t;
	string b = "GEEKS";
	while(t--)
	{
	string a;
	int n;
	cin>>n;
	cin>>a;
	
//	memset(dp,0,sizeof(dp));
	cout<<ans(a,b)<<"\n";
	//for(int i=0;i<n;i++)

	
}
}
