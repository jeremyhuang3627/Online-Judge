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

int d[30 + 5];
int val[30 + 5];
int t[30 + 5];
int dp[30 + 5][1000 + 5 ];

void print(int n,int tt){
	F(i,1,n + 1){
		F(j,1,tt + 1){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	int tt,w;
	while(scanf("%d %d",&tt,&w) != EOF){
		int n;
		scanf("%d",&n);
		F(i,1,n + 1 ){
			scanf("%d %d",&d[i],&val[i]);
			t[i] = 3 * w * d[i];
			//cout << "i " << i << " t[i] " << t[i] <<" d[i] " << d[i] << " val[i] " << val[i] << endl;
		}

		F(i,0,1001){
			dp[0][i] = 0;
		}

		F(i,0,n + 1 ){
			dp[i][0] = 0;
		}

		F(i,1,n + 1){
			F(j,1,tt + 1){
				//cout << "i " << i << " j " << j << endl; 
				if(t[i] <= j){
					if(dp[i-1][j-t[i]] + val[i] > dp[i-1][j]){
						//cout << "dp[i][j] = dp[i-1][j-t[i]] + val[i] " << dp[i-1][j-t[i]] + val[i] << endl;
						dp[i][j] = dp[i-1][j-t[i]] + val[i];
					}else{
						//cout << "dp[i][j] = dp[i-1][j] " << dp[i-1][j] << endl;
						dp[i][j] = dp[i-1][j];
					}
				}else{	
					//cout << "dp[i][j] = dp[i][j-1] " << dp[i][j-1] << endl;
					dp[i][j] = dp[i-1][j];
				}
			}
		}

		cout << dp[n][tt] << endl;

		//print(n,tt);
		int i = n;
		int k = tt;
		vector<int> sol;

		while(i > 0){
			if(dp[i-1][k] != dp[i][k]){
				sol.push_back(i);
				k -= t[i];
				i--;
			}else{
				i--;
			}
		}

		cout << sol.size() << endl;

		sort(sol.begin(),sol.end());

		F(j,0,sol.size())
		{
			cout << d[sol[j]] << " " << val[sol[j]] << endl;
		}

		string s;
		getline(cin,s);
		if(s.empty() && !cin.eof()){
			cout << endl;
		}
	}
	return 0;
}