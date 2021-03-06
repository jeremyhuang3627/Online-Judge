#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 5005

int i,n,a[M];

int f(int s,int e,int b)
{
	if(s>e) return 0;
	int m = min_element(a+s,a+e+1) - a;
	return min(e-s+1,f(s,m-1,a[m]) + f(m+1,e,a[m]) + a[m]-b);
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	cout << f(0,n-1,0);
	return 0;
}