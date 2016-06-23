#include<bits/stdc++.h>
using namespace std;
int ans(int A[],int n)
{
	if(n<=2)return n;
	int dp[n][n];
	int res = 2;
	for(int i=0;i<n;i++)
		dp[i][n-1] = 2;
	
	for(int j=n-2;j>=1;j--)
	{
		int i = j-1,k = j+1;
		while(i>=0 && k<=n-1)
		{
			if(A[i] + A[k] < 2*A[j])
				k++;
			else if(A[i]+A[k]>2*A[j])
			{
				dp[i][j]= 2; i--;
			}
			else
			{
				dp[i][j] = 1 + dp[j][k];
				res = max(res,dp[i][j]);
				i--;k++;
			}
		}
		while(i>=0)
		{
			dp[i][j] = 2;
			i--;
		}
	}
	return res;
}


int main()
{
	int t;cin>>t;while(t--)
	{
		int n;
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)cin>>A[i];
		cout<<ans(A,n)<<"\n";
	}
}



