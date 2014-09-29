#include <iostream>
#include <cstdio>
#include <algorithm>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define LL long long
#define M 100005

using namespace std;
vector<LL> g[M];
LL v[M];
LL t[M];
int n,x,y;

int dfs(int vert){
	if(!g[vert].size()){
		
	}else{

	}
}

int main(){
	scanf("%d",&n);
	F(i,0,n-1){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	F(i,1,n + 1){
		scanf("%d",&v[i]);
	}
	int ans = dfs(1,0);
	return 0;
}