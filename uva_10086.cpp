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
//#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;

int num_rods_sites [30 + 5];
int cost[30 + 5][2 + 1][20 + 5];
int m [30 + 5][300 + 5][300 + 5];
int decision [30 + 5][300 + 5][300 + 5];
int maxInt = 1000 * 300;

int solve(int i,int t1,int t2){
	if(t1 == 0 && t2 == 0){
		return 0;
	}

	if(m[i][t1][t2]){
		return m[i][t1][t2];
	}

	int num_rods = num_rods_sites[i];
	int minimum = 1000 * 300;
	F(j,0,num_rods + 1){
		if(j <= t1 && num_rods - j <= t2){
			int c = solve(i+1,t1-j,t2-(num_rods - j)) + cost[i][1][j] + cost[i][2][num_rods - j];
			if(c < minimum){
				minimum = c;
				decision[i][t1][t2] = j;
			}
		}
	}
	m[i][t1][t2]  = minimum;
	return m[i][t1][t2];
}

void retrievePath(int i,int t1,int t2){
	if(t1 == 0 && t2 == 0){
		return;
	}

	int j = decision[i][t1][t2];
	cout << j <<" ";
	retrievePath(i+1,t1-j,t2-(num_rods_sites[i]-j));
}

int main(){
	int t1,t2,n;
	while(scanf("%d %d",&t1,&t2) != EOF){
		if(t1 == 0 && t2 == 0){
			break;
		}

		fill_n(num_rods_sites,35,0);
		F(i,0,35){
			F(j,0,305){
				fill_n(m[i][j],305,0);
			}
		}

		scanf("%d",&n);
		F(i,1,n + 1){
			scanf("%d",&num_rods_sites[i]);
			F(j,1,num_rods_sites[i] + 1){
				scanf("%d",&cost[i][1][j]);
			}

			F(j,1,num_rods_sites[i] + 1){
				scanf("%d",&cost[i][2][j]);
			}
		}

		int ans = solve(1,t1,t2);

		cout << ans << endl;
		retrievePath(1,t1,t2);
		cout << endl;
		cout << endl;
	}
	return 0;
}