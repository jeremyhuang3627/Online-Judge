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
 
using namespace std;

int d [30];
int t [30];
int val [30];
int used [30];
int maxAmt = 0;
int amt = 0;
vector<int> maxv;
vector<int> v;

void solve(int n,int tt){
	F(i,0,n){
		if(!used[i]){
			if(tt - t[i] >=0){
				used[i] = true;
				amt += val[i];
				v.push_back(i);
				solve(n,tt-t[i]);
				v.pop_back();
				amt -= val[i];
				used[i] = false;
			}else{
				if(maxAmt < amt){
					maxAmt = amt;
					maxv = v;
				}
			}
		}
	}
}

int main(){
	int tt,w;
	while(scanf("%d %d",&tt,&w) != EOF){
		int n;
		scanf("%d",&n);
		fill_n(used,30,0);
		F(i,0,n){
			scanf("%d %d",&d[i],&val[i]);
			t[i] = 3*w*d[i];
		}
		solve(n,tt);
		cout << maxAmt << endl;
		cout << maxv.size() << endl;
		F(i,0,maxv.size()){
			cout << d[maxv[i]] << " " << val[maxv[i]] << endl;
		}
	}
	return 0;
}