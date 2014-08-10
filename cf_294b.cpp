#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a, b)  (a > b ? a : b)
#define M 105
#define MX 1e9

using namespace std;

int w[M],t[M],n,s=0,dp[201];
vector<int> m[3];

int main(){
	cin >> n;
	F(i,0,n){
		cin >> t[i] >> w[i];
		s += t[i];
	}
	F(i,0,n){
		for(int j=s;j>=w[i] + t[i];j--){
			dp[j] = max(dp[j],dp[j - w[i] - t[i]] + t[i]);
		}
	}
	cout << s - dp[s] << endl;
	return 0;
}