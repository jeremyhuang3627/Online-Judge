#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 100005

int dp[3][M],a[3],l,r,m;
char s[M];

int main()
{
	scanf("%s",s + 1);
	for(int i=1;s[i];i++){
		for(int j=0;j<3;j++){
			dp[j][i] = dp[j][i-1] + (s[i] == j + 'x');
		}
	}

	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&l,&r);
		for(int j=0;j<3;j++){
			a[j] = dp[j][r] - dp[j][l-1];
		}
		sort(a,a+3);
		if(r-l<2 || a[2] - a[0] <= 1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}