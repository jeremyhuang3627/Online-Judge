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
#define N 100
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

void print(int * b,int sz){
	printf("-----start----\n");
	F(i,0,sz){
		printf("%d",b[i]);
	}
	printf("\n-----end-----\n");
}

int main(){
	int cn;
	scanf("%d", &cn);
	F(i,0,cn){	
		int n,d;
		scanf("%d %d",&n,&d);

		char c [20];
		int isBig [N + 10];
		Set(isBig,0);
		int sdis [N + 10];
		fill_n(sdis,N+10,d);
		F(j,0,n){
			scanf("%s",c);
			if(c[0] == 'B'){
				isBig[j] = 1;
			}
			sscanf(&c[2],"%d",&sdis[j]);
		}

		int a = -1;
		int apos = 0;
		int b = -1; // indexes of two frogs
		int bpos = 0;
		int maxStep = 0;
		int stepsize;
		while(a < n || b < n){
			if(a == b){
				//cout << "a == b " << endl;;
				if(isBig[a+1]){
					a++;
					b++;
					stepsize = sdis[a] - apos;
					apos += stepsize;
					bpos += stepsize;
				//	cout << " b: " << b << " pos " << bpos << " stepsize " << stepsize << endl;
				//	cout << " a: " << a << " pos " << apos << " stepsize " << stepsize << endl;
				}else{
					a++;
					stepsize = sdis[a] - apos;
					apos += stepsize;
				//	cout << " a: " << a << " pos " << apos << " stepsize " << stepsize << endl;
				}
			}else if(a > b){
				//cout << "a > b" << endl;
				int step = 1;
				if(!isBig[b+1] && a == b + 1 ){
					step ++;
				}
				b += step;
				stepsize = sdis[b] - bpos;
				bpos += stepsize;
				//cout << "b:" << b << " pos " << bpos << " stepsize " << stepsize << endl;
			}else{
				//cout << "a < b" << endl;
				int step = 1;
				if(!isBig[a+1] && b == a + 1 ){
					step ++;
				}
				a += step;
				stepsize = sdis[a] - apos;
				apos += stepsize;
				//cout << "a: " << a << " pos " << apos << " stepsize " << stepsize << endl;
			}
			maxStep = max(maxStep,stepsize);
		}

		printf("Case %d: %d\n",i+1,maxStep);
	}
}