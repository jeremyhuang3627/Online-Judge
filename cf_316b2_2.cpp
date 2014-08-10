#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define N 1005
using namespace std;

int main(){
	int n,x,r[N],p[N],f[N],c,flag,pl;
	scanf("%d%d",&n,&x);
	fill_n(r,N,0);
	fill_n(f,N,0);
	F(i,1,n + 1) scanf("%d",&p[i]),r[p[i]]++;
	f[0] = 1;
	F(i,1,n + 1) if(!r[i]){
		c = 0;flag = -1;
		for(int j=i;j;j=p[j]) {if(j==x) flag = c; c++;}
		if(flag>=0) pl = c - flag;
		else for(int j=n;j>=c;j--) f[j] |= f[j-c];
	}
	F(i,0,n) if(f[i]) printf("%d\n",i + pl);
	return 0;
}