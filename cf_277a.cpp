#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 105

using namespace std;

vector<int> e [M];
vector<int> l [M];
int n,m,v[M],a,b,cnt,d,f;

int visit(int c){
	v[c] = 1;

	F(i,0,e[c].size()){
		F(j,0,l[e[c][i]].size()){
			d = l[e[c][i]][j];
			if(!v[d]){
				visit(d);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n + 1){
		scanf("%d",&a);
		if(!f) f = (a>0);
		F(j,0,a){
			scanf("%d",&b);
			e[i].push_back(b);
			l[b].push_back(i);
		}
	}

	F(i,1,n+1){
		if(!v[i]){
			cnt++;
			visit(i);
		}
	}

	cout << ( f ? --cnt : cnt)<< endl;
	return 0;
}