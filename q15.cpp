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
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;

int x [M + 100];
int y [M + 100];

template<class Iter, class T> Iter binary_find(Iter begin, Iter end, T val)
{
    // Finds the lower bound in at most log(last - first) + 1 comparisons
    Iter i = std::lower_bound(begin, end, val);

    if (i != end && !(val < *i))
        return i; // found
    else
        return end; // not found
}

int main(){
	int c = 0;
	while(true){
		c ++;
		int n,q;
		scanf("%d %d",&n,&q);
		if(n == 0 && q == 0){
			break;
		}

		F(i,0,n)
		{
			scanf("%d",&x[i]);
		}

		sort(x,x + n);

		printf("CASE# %d:\n",c);
		F(i,0,q){
			int val;
			scanf("%d",&val);
			int * p = binary_find(x,x + n,val);
			if(p!= x + n){
				printf("%d found at %ld\n",val,(p - x + 1));
			}else{
				printf("%d not found\n",val);
			}
		}
	}

	return 0;
}