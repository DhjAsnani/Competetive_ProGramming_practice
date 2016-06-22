#include<bits/stdc++.h>
using namespace std;
int ans(string s)
{
	int n = s.length();
	int dp[n][n];
	memset(dp,0,sizeof(dp));
	int i,j;
	for(int k=1;k<n;k++)
	{
		for( j=k, i=0;j<n;j++,i++)
		{
			dp[i][j] = (s[i]==s[j])?dp[i+1][j-1]:(min(dp[i][j-1],dp[i+1][j])+1);
		}
	}
	return dp[0][n-1];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		string s;
		cin>>n>>k;
		cin>>s;
		if(ans(s)>k)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}
