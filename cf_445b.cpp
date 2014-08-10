#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 1005
#define MX 1000005

using namespace std;

int n,m,a,b,cnt;
long long ans=1;
vector<int> g[55];
int v [55];

void dfs(int k){
	v[k] = 1;
	cnt++;
	for(int i=0;i<g[k].size();i++){
		if(!v[g[k][i]]){
			dfs(g[k][i]);
		}
	}
}

long long intpow(int x,int e){
	long long ret = 1;
	for(int i=0;i<e;i++){
		ret*=x;
	}
	return ret;
}

int main(){
	scanf("%d%d",&n,&m);
	F(i,0,m){
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i=1;i<=n;i++){
		if(!v[i]){
			cnt = 0;
			dfs(i);
			ans *= intpow(2,cnt-1);
		}
	}
	return 0;
}