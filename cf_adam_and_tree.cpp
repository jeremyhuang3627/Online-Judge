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

int maxCost = 0;
int color [1000000 + 100][1000000 + 100];

int main(){
	int nn;
	while(scanf("%d",&nn) != EOF){
		map<int,vector<int> > children;
		map<int,int> parent;
		map<int,int> cost;
		
		int node;

		F(i,0,nn){
			scanf("%d",&node);
		
			

			//update cost;
			maxCost = max(maxCost,cost[i + 2]);
			cout << "ans " << cost[i + 2]  << endl;
			cout << endl;
		}
	}
	cout << endl;


	return 0;
}