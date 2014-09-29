#include <iostream>
#include <cstdio>
#include <algorithm>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int a [100 + 5];

int main(){
	int n;
	scanf("%d",&n);

	fill_n(a,105,1);

	a[0] = 2;
	a[1] = 3;

	if(n <=2){
		printf("%d\n",-1);
	}else{
		F(i,0,n){
			printf("%d ", a[i]);
		}
	}

	return 0;
}