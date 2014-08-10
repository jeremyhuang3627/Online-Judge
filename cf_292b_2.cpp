#include <iostream>
#include <cstdio>
#include <algorithm>

#define F(i, a, b) for( int i = (a); i < (b); i++ )

int a [100000 + 100] = {0};

int main(){
	int n,m,x=0,y=0;
	scanf("%d%d",&n,&m);
	int n1,n2;
	//memset(a,0,sizeof(a));

	F(i,0,m){
		scanf("%d %d",&n1,&n2);
		a[n1]++;
		a[n2]++;
	}

	F(i,0,n){
		if(a[i+1]==1) x++;
		else if(a[i+1] == 2) y++;
	}

	if(y==n) {printf("ring topology\n");return 0;}
	if(x==2 && y == n-2) {printf("bus topology\n");return 0;}
	if(x==n-1) {printf("star topology\n");return 0;}
	printf("unknown topology\n");
	return 0;
}