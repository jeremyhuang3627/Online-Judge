#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define mod 1000000007

using namespace std;

long long abc=0,pd,d=1,n;

int main(){
	scanf("%d",&n);
	F(i,1,n+1){
		pd = d;
		d = abc;
		abc = ((2 * abc)%mod + (3 * pd)%mod + mod)%mod;
	}
	printf("%d\n",d);
	return 0;
}