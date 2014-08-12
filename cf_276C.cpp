#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define M 200005

using namespace std;

long long n,p,a[M],l,r,c[M],sum=0;

bool cmp(int i,int j){
	return (i > j);
}

int main()
{
	cin >> n >> p;

	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	for(int i=1;i<=p;i++){
		cin >> l >> r;
		c[l]++;
		c[r+1]--;
	}
	
	for(int i=1;i<=n;i++){
		c[i] += c[i-1];
	}
	
	sort(c+1,c+n+1,cmp);
	sort(a+1,a+n+1,cmp);

	for(int i=1;i<=n;i++){
		sum += a[i] * c[i];
	}

	cout << sum << endl;
	return 0;
}