#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

vector<int> t[50005];
int d[50005][505],n,k,a,b,s,ans=0;

int dfs(int node,int p){
	d[node][0] = 1;
	F(i,0,t[node].size()){
		if(t[node][i]!=p){
			dfs(t[node][i],node);
			F(j,0,k) ans += d[node][j]*d[t[node][i]][k-j-1];
			F(j,0,k) d[node][j+1] += d[t[node][i]][j]; 
		}
	}
}

int main(){
	scanf("%d%d",&n,&k);
	F(i,0,n-1){
		scanf("%d%d",&a,&b);
		t[a].push_back(b);
		t[b].push_back(a);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}