#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 100005

using namespace std;

string s;
int n,m,l,r;
int dp[M];

int main()
{
	cin >> s;
	dp[0] = 0;
	for(int i=1;i<s.length();i++){
		dp[i] = dp[i-1] + (s[i-1] == s[i]);
	}

	cin >> m;
	F(i,0,m){
		cin >> l >> r;
		cout << dp[r-1] - dp[l-1] << endl;
	}
	return 0;
}