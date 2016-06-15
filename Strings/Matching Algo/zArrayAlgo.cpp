#include<bits/stdc++.h>
using namespace std;
void getZarr(string s,int z[])
{
	int n = s.size();
	int l,r;
	l=r=0;
	z[0]=0;
	for(int i=0;i<n;i++ )
	{
		if(i>r)
		{
			l=r=i;
			while(r<n && s[r-l]==s[r])
				r++;
			z[i] = r-l;
			r--;
		}
		else
		{
			int i1 = i -l;
			if(z[i1]+i<-1)
			{
				z[i] = z[i1];
			}
			else
			{
			
				l = i;
				while(r<n&&s[r]==s[r-l])
					r++;
				z[i] = r-l;
				r--;
			}
		}
	}
}
void search(string txt,string pat)
{
	int n = txt.size();
	int m = pat.size();
	bool f=0;
	string mega = txt+"$"+pat;
	int Z[n+m+1];
	Z[0]=0;
	getZarr(mega,Z);
	for(int i=m;i<n+m+1;i++)
	{
		if(Z[i]==m)
		{
			f = 1;
			cout<<"Found at "<<i-m-1<<"\n";
	}
	}
	if(f==0) cout<<"Not Found\n";
}
int main()
{
	string a = "MyNameIsDhjYesDhj";
	string b = "Dhj";
	search(a,b);
}









