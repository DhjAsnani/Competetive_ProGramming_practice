#include<bits/stdc++.h>
using namespace std;
// this solution requires O(n*n) space
int solution(int S[],int n,int m)
{
	int table[n+1][m];
	for(int i=0;i<m;i++)
		table[0][i] = 1;
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = (i-S[j]>=0)?table[i-S[j]][j]:0;
			int y = (j>=1)?table[i][j-1]:0;
			table[i][j] = x+y;
		}
	}
	return table[n][m-1];
	
}
// O(n) space solution
int solution2(int S[],int n,int m)
{
	int mod = 1000007;
	int table[n+1];
	memset(table,0,sizeof(table));
	table[0] = 1;
	for(int i=0;i<m;i++)
		for(int j=S[i];j<n+1;j++)
		{
		
		{ table[j] = table[j] + table[j-S[i]];
		table[j]%=mod;
	
		}
		
	}
	return table[n]%mod;
}
int main()
{
	int S[]={1,3,2};
	cout<<solution2(S,4,3);
}











