#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 150005


using namespace std;

int n,k,a[M],s[M],sum=0,m=1E9;

int main(){
	cin >> n >> k;
	F(i,1,n + 1){
		cin >> a[i];
		sum+=a[i];
		s[i] = sum;
	}

	F(i,1,n + 1 -k){
		sum = s[i+k]- s[i-1];
		m = min(m,sum);
	}
	cout << m << endl;
	return 0;
}