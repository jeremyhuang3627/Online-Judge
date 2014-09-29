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

LL m [65 + 5][65 + 5][2 + 1]; 

void solve(){
	m[1][0][0] = 1;
	m[1][0][1] = 0;

	m[1][1][1] = 1;
	m[1][1][0] = 0;

	F(i,2,66){
		F(j,0,66){
			if(j<=i){
				if(j > 0){
					m[i][j][1] = m[i-1][j-1][1] + m[i-1][j-1][0];
				}else{
					m[i][j][1] = 0;
				}
				m[i][j][0] = m[i-1][j+1][1] + m[i-1][j][0];
			}else{
				m[i][j][0] = 0;
				m[i][j][1] = 0;
			}
		}
	}
}

int main(){
/*	 std::clock_t start;
    double duration;
    start = std::clock(); */

	int n,s;
	solve();
	while(true){
		scanf("%d %d",&n,&s);
		if(n == -1 && s == -1){
			break;
		}
		cout << m[n][s][0] + m[n][s][1] << endl; 
	}

/*	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"printf: "<< duration <<'\n'; */
	return 0;
}