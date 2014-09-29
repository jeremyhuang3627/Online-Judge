#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define mod 1000000007

using namespace std;

int n,k,d,ans=0;
long long dp[105][3];

int main(){
	scanf("%d%d%d",&n,&k,&d);
	
	dp[0][0] = 1;
	F(i,1,n+1){
		F(j,1,(i<d?i+1:d)){
			dp[i][0] =  (dp[i][0] + dp[i-j][0])%mod;
		}
		if(i>=d){
			F(j,1,d){
				dp[i][1] =  (dp[i][1] + dp[i-j][1])%mod;
			}

			F(j,d,min(i,k) + 1){
				dp[i][1] = (dp[i][1] + dp[i-j][0] + dp[i-j][1])%mod;
			}
		}else{
			dp[i][1] = 0;
		}

	}

	cout << dp[n][1] << endl;
	return 0;
}