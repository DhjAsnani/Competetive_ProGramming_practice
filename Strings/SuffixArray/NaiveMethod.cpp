#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct suffix
{
	int intex;
	char *suff;
};

int compare(suffix a,suffix b)
{
	return strcmp(a.suff,b.suff)<0?1:0;
}
void buildSuffArray(char *txt,int n)
{
	suffix suffixes[n];
	for(int i=0;i<n;i++)
	{
		suffixes[i].intex = i;
		suffixes[i].suff = (txt + i);
	}
	sort(suffixes,suffixes+n,compare);
	for(int i=0;i<n;i++)
		cout<<suffixes[i].intex<<" ";
}

int main()
{
	char *txt = "banana";
	buildSuffArray(txt,strlen(txt));
	
}











