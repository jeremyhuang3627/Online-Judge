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

int x [M + 100]; 
int segTree [4*M + 100];

void buildTree(int at,int lo, int hi){
	if(lo == hi){
		segTree[at] = x[lo];
		return;
	}

	int mid = (lo + hi) / 2;

	buildTree(2 * at,lo,mid);
	buildTree(2 * at + 1,mid+1,hi);

	segTree[at] = segTree[2 * at] * segTree[2 * at + 1];
}

void update(int at,int val,int idx,int lo, int hi){
	if(idx < lo || idx > hi){
		return;
	}

	if(lo==hi){
		segTree[at] = val;
		return;
	}

	int mid = (lo + hi) / 2; 
	update(at * 2,val,idx,lo,mid);
	update(at * 2 + 1, val,idx, mid + 1,hi);

	segTree[at] = segTree[2 * at] * segTree[2 * at + 1];
}

int query(int at,int lo,int hi,int start, int end){
	if(start > hi || end < lo){
		return 1;
	}

	if(lo >= start && hi <= end){
		return segTree[at];
	}
	int mid = (lo + hi)/2;
	return query(at * 2,lo, mid, start, end) * query(at * 2 + 1, mid + 1, hi, start, end);
}

void print()
{
    printf ("\n... printing start... \n");
    F(i, 0, 100) {
        printf (" %d", segTree [i]);
    }
    printf ("\n... printing end... \n");
}

int main(){
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF){
		F(i,0,n){
			scanf("%d",&x[i]);
			if(x[i] > 1 ) x[i] = 1;
			if(x[i] < -1) x[i] = -1;
		}
		buildTree(1,0,n-1);
		//printf("Building tree\n");
		//print();
		char cmd [5];
		F(i,0,k){
			scanf("%s",cmd);
			if(cmd[0] == 'C'){
				int idx,val;
				scanf("%d %d",&idx,&val);
				idx --;

				if(val > 1) val = 1;
				if(val < -1) val = -1;

				update(1,val,idx,0,n-1);
				x[idx] = val;
			}else{
				int start,end;
				scanf("%d %d",&start,&end);
				start --;
				end --;
				int q = query(1,0,n-1,start,end);
				if(q==1){
					printf("+");
				}else if(q==0){
					printf("0");
				}else{
					printf("-");
				}
			}
		}
		printf("\n");
	}
	return 0;
}