#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define LL long long

using namespace std;

int dp [1000 + 5];
int sp [1000 + 5];

int main(){
	int n;
	scanf("%d",&n);
	int m = 1000000007;
	F(i,1, n + 1){
		scanf("%d",&sp[i]);
	}

	dp[1] = 0;
	F(i,2,n+2){
		dp[i] = (2*dp[i-1] + 2 - dp[sp[i-1]])%m;
		if (dp[i] < 0)
			dp[i] += m;
	}

	printf("%d\n",dp[n+1]);
	return 0;
}