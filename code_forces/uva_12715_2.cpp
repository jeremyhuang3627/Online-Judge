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
#define pii pair<LL,LL>

using namespace std;

pii query [100000 + 5];
pii ps [100000 + 5];
LL ans [100000 + 5];

bool cmp(pii a,pii b){
	return ((a.first < b.first) || (a.first == b.first) && a.second > b.second );
}

int main(){
	int cn;
	scanf("%d",&cn);
	while(cn--){
		int n,m,cur=0;
		scanf("%d %d",&n,&m);

		F(i,0,n){
			scanf("%lld %lld",&query[i].first,&query[i].second);
		}

		F(i,0,m){
			scanf("%d",&ps[i].first);
			ps[i].second = i;
		}

		sort(query, query + n, cmp);
		sort(ps,ps + m);

		F(i,1,n){
			if(query[i].second > query[cur].second){
				query[++cur] = query[i];
			}
		}
 
 		n = cur + 1; cur = 0;

 		F(i,0,m){
 			int pos = ps[i].first;
 			LL &mn = ans[ps[i].second] = 0;

 			if (cur >= n) cur = n - 1;
 			while(cur < n){
 				if(pos > )
 			} 
 		}

	}
	return 0;
}