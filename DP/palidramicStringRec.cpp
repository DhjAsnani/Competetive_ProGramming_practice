#include<bits/stdc++.h>
using namespace std;
int ans(string s,int l,int h)
{
	if(l>h) return INT_MAX;
	if(l==h) return 0;
	if(l==h-1) return (s[l]==s[h])?0:1;
	return (s[l]==s[h])? ans(s,l+1,h-1):min(ans(s,l+1,h),ans(s,l,h-1))+1;
}
int main()
{
	string a="abac";
	cout<<ans(a,0,3);
}
