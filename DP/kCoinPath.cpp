#include<bits/stdc++.h>
using namespace std;
int no0fPaths(int S[3][3],int coin)
{
	int dp[3][3][coin];
	dp[0][0][0] = 1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int c=1;c<=coin;c++)
			{
				if(coin-S[i][j]<0)
				{
					continue;
				}
				if(i-1>=0)
				{
					dp[i][j][coin] += dp[i-1][j][coin-S[i][j]];
				}
				if(j-1>=0)
				{
					dp[i][j][coin] += dp[i][j-1][coin-S[i][j]];
				}
				
			}
		}
	}
	return dp[coin][2][2];
}
int main(){ 

int S[3][3]={{1,2,3},{4,6,5},{3,2,1}};
cout<<no0fPaths(S,12);
}






