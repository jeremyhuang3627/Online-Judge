#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

#define M 100001

long long n,k,a[M],r=0,p=0,w=0,e;

int main()
{	
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		while(r+p*(a[i]-a[i-1]) > k) r-= a[i-1]-a[i-p],p--;
		r += p*(a[i]-a[i-1]);
		p++;
		if(p>w)
			w=p,e=a[i];
	}
	cout << w << " " << e << endl;
	return 0;
}