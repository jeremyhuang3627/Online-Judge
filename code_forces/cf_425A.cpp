#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

#define M 205

int n,k,a[M],b[M],c[M],l,r,ans;

int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	ans = -(1<<28);

	for(int l=0;l<n;++l)for(int r=l+1;r<=n;++r) {
		copy(a+l,a+r,b);
		copy(a,a+l,c);
		copy(a+r,a+n,c+l);

		int x = r-l,y=n-x;
		sort(b,b+x),sort(c,c+y);
		for(int _=k,i=0,j=y-1; _-- && i<x && j >=0 && c[j] > b[i];i++,j--){
			swap(c[j],b[i]);
		}

		//int sum = accumulate(b,b+x,0); 
		ans  = max(ans,accumulate(b,b+x,0));
	}

	cout << ans << endl;

	return 0; 
}