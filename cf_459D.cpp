#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

#define M 1000001

using namespace std;

int n,a[M],b[M],st[M];
map<int,int> m;
long long ans=0;

int main()
{	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i] = ++m[a[i]];
	}
	for(int i=0;i<n;i++){
		ans += i;
		for(int j=m[a[i]]-b[i] + 1;j;j-=j&(-j)) ans -= st[j];
		for(int j=b[i];j<M;j+=j&(-j)) ++st[j];
	}
	cout << ans << endl;
	return 0;
}