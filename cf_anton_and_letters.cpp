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

int alpha [26 + 1];

int main(){
	string l;

	while(getline(cin,l)){
	//	cout << "l " << l << endl;
		int i = 0;
		int cnt = 0;
		fill_n(alpha,26 + 1,0);
		while(l[i] != '\0'){
			if(isalpha(l[i]) && !alpha[l[i] - 'a']){
				alpha[l[i] - 'a'] = true;
				cnt ++;
			}
			i++;
		}
		cout << cnt << endl;
	}

	return 0;
}
