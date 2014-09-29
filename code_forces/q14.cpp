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
#define M 1000000
#define LL long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;

int x [M];

int getEarlyT(int l,int n){
	int t = 0;
	F(i,0,n){
		t = max(min(l-x[i],x[i]),t);
	}
	return t;
}

int getLateT(int l,int n){
	int t = 0;
	F(i,0,n){
		t = max(max(l-x[i],x[i]),t);
	}
	return t;
}

int main(){
	int cn;
	scanf("%d",&cn);
	F(i,0,cn){
		int l,n;
		scanf("%d %d",&l,&n);
		F(j,0,n){
			scanf("%d",&x[j]);
		}
		int et = getEarlyT(l,n);
		int lt = getLateT(l,n);
		printf("%d %d\n",et,lt);
	}
	return 0;
}

