#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a,b)  (a > b ? b : a)
#define max(a,b) (a > b ? a : b)
#define N 100005

using namespace std;

int a[N],l[N],r[N],n,ans=0;

int main(){
	scanf("%d",&n);
	F(i,1,n + 1) scanf("%d",&a[i]);
	l[1] = r[n] = 1;
	F(i,2,n + 1) a[i]>a[i-1] ? l[i] = l[i-1]+1:l[i] = 1;
	for(int i=n;i>1;i--) a[i] > a[i-1] ? r[i-1] = r[i] + 1 : r[i-1] = 1;

	F(i,1,n+1){
		if(l[i-1] + 1 + r[i+1] > ans && a[i+1] > a[i-1] + 1) ans = l[i-1] + 1 + r[i+1];
		if(l[i-1] + 1 > ans) ans = l[i-1] + 1;
		if(r[i+1] + 1 > ans) ans = r[i+1] + 1;
	}

	cout << ans << endl;
	return 0;
}