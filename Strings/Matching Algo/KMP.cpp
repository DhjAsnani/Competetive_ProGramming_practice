// src http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/
#include<bits/stdc++.h>
using namespace std;
void LPSArray(char *pat,int M, int *lps)
{
int len = 0;
lps[0] = 0;
int i=1;
 while (i < M)
    {
       if (pat[i] == pat[len])
       {
         len++;
         lps[i] = len;
         i++;
       }
       else 
       {
         if (len != 0)
         {
          
           len = lps[len-1];
 
           
         }
         else 
         {
           lps[i] = 0;
           i++;
         }
       }
    }
}
void KMP(char *pat,char * txt)
{
	int n = strlen(pat);
	int m = strlen(txt);
	int *lps = new int[n];
	int j = 0;
	LPSArray(pat,n,lps);
	int i = 0;
	while(i<m)
	{
		if(pat[j] == txt[i])
		{
			i++;j++;
		}
		if(j==n)
		{
			cout<<"FOUND\n";
			j= lps[j-1];
		}
		else if(i<m && pat[j]!=txt[i])
		{
			if(j!=0)
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
}
int main()
{
	char *pat = "ABABCABAXB";
	char *txt="ABABDABACDABABCABAB";
	KMP(pat,txt);
	
}
