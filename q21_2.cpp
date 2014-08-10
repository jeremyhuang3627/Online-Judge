#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
 
#define Inf 2147483647
#define Pi acos(-1.0)
#define N 21;
#define M 10000
#define LL long long
#define ULL unsigned long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;

int cur [21 + 5];
LL m [10000][21];

void solve(){
	F(i,0,10000)
	{
		fill_n(m[i],21,0);
	}

	F(i,0,21){
		m[0][i]=1;
	}

	F(i,0,10000){
		m[i][0]=1;
	}

	F(i,1,10000){
		F(j,1,21){
			if(cur[j] <= i) 
			{
				m[i][j] = m[i][j-1] + m[i-cur[j]][j];
			}else{
				m[i][j] = m[i][j-1];
			}
		}
	}
}

int main(){

	F(i,0,21){
		int val = i + 1;
		cur[i] = (val * val * val);
	}

	solve();

	int n;
	while(scanf("%d",&n) != EOF)
	{
		LL ans = m[n][20];
		printf("%lld\n",ans);
	}

	return 0;
}