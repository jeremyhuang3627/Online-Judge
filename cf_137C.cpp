#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 100005

int n;
long long c,l;
int main()
{
	cin >> n;
	pair<int,int> a[M];
	for(int i=0;i<n;i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(a[i].second < c) l++;
		else c = a[i].second;
	}
	cout << l << endl;
	return 0;
}