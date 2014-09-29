#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define MX 1005
#define MOD 1000000007

long long T,N,M,g[MX],f[MX],h[MX];

long long int_pow(long long n,long long x){
	int ret = 1;
	for(int i=0;i<x;i++){
		ret = (ret*n)%MOD;
	}
	return ret;
}

int main()
{
	cin >> T;
	f[0] = 1;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=4;j++)
			if(i-j >= 0) f[i] = (f[i] + f[i-j])%MOD;

	while(T--){
		cin >> N >> M;
		for(int i=1;i<=M;i++){
			g[i] = int_pow(f[i],N);
		}
		for(int i=1;i<=M;i++){
			h[i] = g[i];
			long long tmp = 0;
			for(int j=1;j<i;j++){
				tmp = (tmp + h[j]*g[i-j])%MOD;
			}
			h[i] = (h[i] - tmp + MOD)%MOD;
		}
		cout << h[M] << endl;
	}
	return 0;
}