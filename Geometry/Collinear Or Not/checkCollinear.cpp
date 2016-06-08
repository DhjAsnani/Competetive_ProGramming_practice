#include<iostream>
#include<vector>
using namespace std;
vector <int> CrossProduct(vector<int> const &a,vector<int> const &b )
{
	vector<int> res (a.size());
	res[0] = a[1]*b[2]-a[2]*b[1];
  	res[1] = a[2]*b[0]-a[0]*b[2];
  	res[2] = a[0]*b[1]-a[1]*b[0];
  return res;
}

int main()
{
	
	vector<int> a,b,c,ab,ac;
	a.push_back(4);
	a.push_back(4);
	a.push_back(4);
	b.push_back(6);
	b.push_back(6);
	b.push_back(6);
	c.push_back(8);
	c.push_back(8);
	c.push_back(8);
	int ii;
	
	for (ii=0;ii<=a.size();ii++)
	{
	ab.push_back(a[ii]-b[ii]);
	ac.push_back(a[ii]-c[ii]);
	//ac[ii] = a[ii]-c[ii];
	}
	

	vector<int> ans;
	ans = CrossProduct(ab,ac);
	for(int i=0;i<a.size();i++)
	{
		if(ans[i] !=0)
		{
			cout<<"Not Collinear"<<endl;
			return 0;
		}
		else
		{
			continue;
		}
	}
	
		cout<<"Collinear"<<endl;
	return 0;
	
}
