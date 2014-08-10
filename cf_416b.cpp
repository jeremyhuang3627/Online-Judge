#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a,b)  (a > b ? b : a)
#define max(a,b) (a > b ? a : b)
#define M 50005

int m,n,t[M][6],d[M][6];

int main(){
	scanf("%d%d",&m,&n);
	F(i,1,m+1) F(j,1,n + 1) scanf("%d",&t[i][j]);
	F(i,0,m+1) d[i][0] = 0;
	F(i,0,n+1) d[0][i] = 0;
	F(i,1,m + 1) F(j,1,n+1) d[i][j] = max(d[i-1][j],d[i][j-1]) + t[i][j];
	F(i,1,m+1) printf("%d ",d[i][n]);
	printf("\n");
	return 0;
}