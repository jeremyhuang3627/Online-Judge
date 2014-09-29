#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a, b)  (a < b ? b : a)
#define M 4005

using namespace std;

int l[3],n,dp[M],m,ans=0;

int main()
{
	cin >> n >> l[0] >> l[1] >> l[2] ;

	m = l[0];
	for(int i=0;i<3;i++){
		m = min(m,l[i]);
	}

	dp[0] = 0;
	for(int i=1;i<=n;i++){
		dp[i] = -1;
		if(i>=m){
			for(int j=0;j<3;j++){
				if(i>=l[j] && dp[i-l[j]] != -1){
					dp[i] = max(dp[i],dp[i-l[j]] + 1);
				}
			}
		}
		ans = max(dp[i],ans);
	}
/*
	for(int i=0;i<=n;i++){
		cout << dp[i] << " ";
	}
	cout << endl; */
	cout << dp[n] << endl;
	return 0;
}