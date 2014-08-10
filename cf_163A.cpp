#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define mod 1000000007;

char s[5005],t[5005];
int i,j,d[5005][5005],ans=0;

int main()
{
	gets(s);
	gets(t);

	for(i=0;s[i];i++){
		for(j=0;t[j];j++){
			if(j==0){
				d[i][j] = (int(s[i] == t[j]) ) % mod;
			}else if(i==0){
				d[i][j] = (d[i][j-1] + int(s[i] == t[j]) ) % mod;
			}else{
				d[i][j] = (d[i][j-1] + (s[i]==t[j]) * (d[i-1][j-1] + 1) ) % mod;
			}
		}
	}

	for(i=0;s[i];i++){
		ans = (ans + d[i][j-1])%mod;
	}
	cout << ans << endl;
	return 0;
}