#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define mod 1000000009
#define max(a,b) ((a > b) ? a : b)

long long n,m,k,x,c,s=0;

long long pow_sqr(long long x,long long n){
	if(n==0) return 1;
	if(n==1) return x;
	if(n%2==0) return pow_sqr((x*x)%mod,n/2);
	else return (x*pow_sqr((x*x)%mod,(n-1)/2))%mod;
}

int main()
{
	cin >> n >> m >> k;
	x = max(0,m - n%k - n/k * (k-1));
	long long l = ((pow_sqr(2,x+1) - 2 + mod)%mod*k)%mod;
	cout << (l + m - x*k)%mod << endl;
	return 0;
}