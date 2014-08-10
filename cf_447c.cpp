#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define N 100005;

using namespace std;

int a[N],b[N],c[N],d[N],n;

int main(){
	scanf("%d",&n);
	F(i,1,n+1){
		scanf("%d",&a[i]);
	}
	b[1] = a[1];c[1] = 1;
	F(i,2,n+1){
		if(a[i]>b[i-1]){
			b[i] = a[i];
			d[i] = d[n-1];
		}else{
			b[i] = b[i-1];
			d[i] = i;
		}
		c[i] = c[i-1] + 1;
	}
	return 0;
}