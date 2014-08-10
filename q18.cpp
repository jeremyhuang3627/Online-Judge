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
#define M 100000
#define LL long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;

int main(){
	int cn;
	scanf("%d",&cn);
	F(i,0,cn){
		int n;
		scanf("%d",&n);
		int n_arr[M + 100];
		int diff_arr[M + 100];
		int prev = 0;
		int maxgaps_arr [M + 100];
		Set(maxgaps_arr,0);
		int maxgap = 0;
		int maxgapIdx = 0;
		F(j,0,n){
			scanf("%d",&n_arr[j]);
			diff_arr[j] = n_arr[j] - prev;
			prev = n_arr[j];
			if(diff_arr[j] > maxgap){
				maxgapIdx = j;
				maxgap = diff_arr[j];
			}
		}

		int minstrength = maxgap;
		int idx = 0;
		F(j,maxgapIdx + 1,n){	
			if(diff_arr[j] == maxgap - idx){
				minstrength++;
				break;
			}else if(diff_arr[j] == maxgap - idx - 1){
				idx ++;
			}
		}
		printf("Case %d: %d\n",i+1,minstrength);
	}
	return 0;
}