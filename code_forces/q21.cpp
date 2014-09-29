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
#define N 21;
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

int x [21 + 5];
ULL l [M + 100];
map<vector<int> , bool> existed;
vector<int> v;

void print(vector<int> v)
{
	F(i,0,v.size()){
		cout << v[i] << " ";
	} 
	cout << endl;
}

ULL getNumWays(int amt)
{
	//cout << "amt " << amt << endl;
	if(amt < 0){
		return 0;
	}

	if(l[amt]){
		return l[amt];
	}
	ULL num = 0;
	F(i,0,21){
		v[x[i]]++;
		num += getNumWays(amt-x[i]);
		v[x[i]]--;
	}
	l[amt] = num;
	return l[amt];
}

int main(){
	int amt;
	v.resize(21);
	F(i,0,21){
		int val = i + 1;
		x[i] = (val * val * val);
		//cout << "x["<< i <<"] " << x[i] << endl; 
	}

	fill_n(l,M + 100,0); 

	getNumWays(9999);

	while(scanf("%d",&amt) != EOF){
		cout << "amt " << amt << endl;
		ULL nways = getNumWays(amt);
		cout << nways << endl;
	}

	return 0;
}

