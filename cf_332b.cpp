#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 200005

using namespace std;

int n,k,_a,_b,idx=-1,a[M];

long long r[M],rdx[M],s[M],sum,m;

int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n + 1){
		scanf("%d",&a[i]);
	}

	for(int i=n;i>=1;i--){
		sum += a[i];
		if( (n-i+1) >=k){ sum -= a[i + k]; s[i] = sum;}
		else s[i] = 0;

		if(s[i] >= m){m = s[i];idx = i;}
		r[i] = m; rdx[i] = idx;
	}

	m = 0;
	F(i,1,n-2*k+2){
		if(s[i] + r[i+k] > m){
			m = s[i] + r[i+k];
			_a = i; _b = rdx[i+k];
		}
	}
	cout << _a << " " << _b << endl;
	return 0;
}