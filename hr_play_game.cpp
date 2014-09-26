#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MX 100005
#define max(a,b) ((a>b)?a:b)

long long T,N,a[MX],dp[MX],sum[MX];

int main(){
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0;i<N;i++) cin >> a[i];
		reverse(a,a+N);
		for(int i=0;i<N;i++) sum[i] = (i?sum[i-1] + a[i]:a[i]);
		dp[0] = a[0];
		dp[1] = dp[0] + a[1];
		dp[2] = dp[1] + a[2];
		for(int i=3;i<N;i++){
			dp[i] = max(-1LL,sum[i-1] - dp[i-1] + a[i]);
			dp[i] = max(dp[i],sum[i-2] - dp[i-2] + a[i] + a[i-1]);
			dp[i] = max(dp[i],sum[i-3] - dp[i-3] + a[i] + a[i-1] + a[i-2]);
		}
		cout << dp[N-1] << endl;
	}
	return 0;
}