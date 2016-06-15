#include<bits/stdc++.h>
using namespace std;
long hash(char *pat,int p)
{
	long hashVal = (int)pat[0];
	int k = p;
	for(int i=1;i<strlen(pat);i++)
	{
		
		hashVal+=(int)pat[i]*p;
		p=p*k;
	 } 
	 return hashVal;
}
long reHash(char oldc,char newc,int p,int m,long hash)
{
	long newHash = (hash - (int)oldc)/p + (int)newc * pow(p,m-1);
	return newHash;
}
bool search(char *txt, char *pat,int p)
{
	int m = strlen(pat);
	int n = strlen(txt);
	long patHash = hash(pat,p);
	long txtHash = 0;
	for(int i=0;i<n-m+1;i++)
	{
		if(i==0)
		{
			char *c;
			for(int j=0;j<m;j++)
			{
				c[j]=txt[j];
			}
			txtHash = hash(c,p);
			if(txtHash == patHash)
				return true;
			
		}
		if(i!=0)
		{
			txtHash = reHash(txt[i-1],txt[i+m-1],p,m,txtHash);
			if(txtHash == patHash)
				return true;
		}
	}
}
int main()
{
	char *txt = "kkabckk";
	char *pat = "abco";
	cout<<search(txt,pat,3);
}
