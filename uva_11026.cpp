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

LL x [1000 + 5];
LL t [1000 + 5][1000 + 5];


int main(){
	int n,m;
	fill_n(t[0],1005,0);
	while(scanf("%d %d",&n,&m) != EOF){
		if(n == 0 && m == 0){
			break;
		}
	
		F(i,1,n + 1){
			scanf("%lld",&x[i]);
		}

		LL sum;
		LL maxMod = 0;
		F(i,1,n + 1){
			F(j,1,n + 1){
				if(j<=i){
					if(j==1){
						sum = 0;
						F(k,1,i+1){
							sum = (sum + x[k])%m;
						}
						t[i][j] = sum%m;
					}else{
						t[i][j] = ((t[i-1][j-1] * x[i]) % m + t[i-1][j]) % m;
						//maxMod = max(maxMod,t[i][j]);
						//cout << " modval " << modval << endl;
					}
				}else{
					t[i][j] = 0;
				}
				//cout << t[i][j] << " ";
			}
			//cout << endl;
		}


		F(i,1,n + 1 ){
			maxMod = max(t[n][i],maxMod);
		}
		cout << maxMod << endl;
	}
	return 0;
}