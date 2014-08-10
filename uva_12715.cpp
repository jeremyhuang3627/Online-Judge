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

int maxCov;

struct ITNode{
	pair<int,int> i;
	ITNode * left;
	ITNode * right;
	int maxHi;
};

ITNode * makeNode(int lo,int hi){
	ITNode * n = new ITNode();
	n->i = make_pair(lo,hi);
	n->left = NULL;
	n->right = NULL;
	n->maxHi = hi;
	return n;
}

void insert(ITNode * &r, ITNode * n){
	if(r == NULL){
		r = n;
		return;
	}

	if(r->i.first >= n->i.first){
		insert(r->left,n);
	}else{
		insert(r->right,n);
	}
	r->maxHi = max(r->maxHi,n->maxHi);
}

bool inRange(ITNode * r,int stab){
	return (r->i.first <= stab && r->i.second >= stab);
}

int getCov(ITNode * r,int stab){
	int lo = r->i.first;
	int hi = r->i.second;
	return min(stab - lo,hi - stab);
}

void query(ITNode * r, int stab){
	if(r == NULL){
		return;
	}

	if(inRange(r,stab)){
		maxCov = max(maxCov,getCov(r,stab));
	}

	if(stab > r->maxHi){
		return;
	}

	if(stab > r->i.first){
		query(r->left,stab);
		query(r->right,stab);
	}else{
		query(r->left,stab);
	}
}	

int main(){
	int cn;
	scanf("%d",&cn);
	F(i,0,cn){
		int n,m;
		scanf("%d %d",&n,&m);
		ITNode * root = NULL;
		int l,r;
		F(j,0,n){
			scanf("%d %d",&l,&r);
			ITNode * node = makeNode(l,r);
			insert(root,node);
		}

		int x;
		F(j,0,m){
			scanf("%d",&x);
			maxCov = 0;
			query(root,x);
			cout << maxCov << endl;
		}
	}
	return 0;
}