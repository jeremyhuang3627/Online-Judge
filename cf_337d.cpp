#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 100005

using namespace std;

int n,m,d,a[M],v1,v2,c[M],ans,up[M],down[M],down2[M],f=0,mark,parent[M],val;
vector<int> b[M];

int markDown(int node,int p){
	down[node] = (a[node] ? 0 : -1e9);
	parent[node] = p;
	F(j,0,b[node].size()){
		if(b[node][j]!=p){
			val = markDown(b[node][j],node) + 1;
			if(val >= down[node]){
				down2[node] = down[node];
				down[node] = val;
			}else if(val > down2[node]){
				down2[node] = val;
			}
		}
	}
	return down[node];
}

void markUp(int node,int p){
	up[node] = (a[node] ? 0 : -1e9);
	if(p!=0){
		if(down[node] + 1 == down[p]){
			up[node] = max(up[node],down2[p] + 1);
		}else{
			up[node] = max(up[node],down[p] + 1);
		}
		up[node] = max(up[node],up[p]+1);
	}

	F(i,0,b[node].size()){
		if(b[node][i]!=p){
			markUp(b[node][i],node);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&d);
	F(i,1,m + 1){
		scanf("%d",&mark);
		a[mark] = 1;
	}
	F(j,0,n-1){
		scanf("%d%d",&v1,&v2);
		b[v1].push_back(v2);
		b[v2].push_back(v1);
	}
	markDown(1,0);
	markUp(1,0);
	F(i,1,n+1){
		//cout << "down[" << i << "] " << down[i] << " up["<< i <<"] " << up[i] << endl;
		if(down[i]<=d  && up[i] <= d){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}