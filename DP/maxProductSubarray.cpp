#include<bits/stdc++.h>
using namespace std;

long ans(vector<int> &A)
{
int curr_max_prod = A[0];
int prev_max_prod = A[0];
int prev_min_prod = A[0];
int curr_min_prod = A[0];
int ans = A[0];
for(int i=1;i<A.size();i++)
{
	if(A[i]==0)
	{
		curr_max_prod = 0;
		curr_min_prod = min(curr_min_prod*A[i],0);
	}
	if(A[i]>0)
	{
		if(curr_min_prod<0) curr_min_prod = curr_min_prod*A[i];
		curr_max_prod = max(A[i],curr_max_prod*A[i]);
	}
	if(A[i]<0)
	{
		if(curr_min_prod==0) curr_min_prod = min( A[i],curr_min_prod);
		else curr_min_prod*=A[i];
	}
	if(curr_min_prod>curr_max_prod)
	{
		curr_max_prod = curr_min_prod;
		curr_min_prod = 1;
	}
	ans = max(curr_max_prod,ans);
		
	
}

return ans;
}
int main()
{
    vector<int> A;
   
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);
    A.push_back(0);
    A.push_back(-9);
    A.push_back(-10);
    A.push_back(4);
    
    
    
    
    printf("Maximum Sub array product is %d", 
            ans(A));
    return 0;
}

