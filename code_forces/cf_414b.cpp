#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 2005
#define mod 1000000007

using namespace std;

int n,k,cnt=0,dp[M][M];
vector<int> d[M];

int main(){
	scanf("%d%d",&n,&k);
	F(i,0,n+1){
		dp[0][i] = 1;
	}

	F(i,1,n + 1){
		F(j,i,n+1){
			if(j%i==0){
				d[i].push_back(j);
			}
		}
	}

	F(i,1,k){
		F(j,1,n+1){
			F(l,0,d[j].size()){
				dp[i][j] = (dp[i][j] + dp[i-1][d[j][l]])%mod;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		cnt = (cnt + dp[k-1][i])%mod;
	}
	cout << cnt << endl;
	return 0;
}