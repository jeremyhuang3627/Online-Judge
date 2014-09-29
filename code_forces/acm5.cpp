#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 105

int N,dst[MAXN][MAXN];
char g[MAXN][MAXN];
bool okc[256];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

int bfs(){
	queue<PII> q;
	REP(i,0,N) REP(j,0,N) dst[i][j] = INF;
	dst[0][0] = 1;
	if(okc[g[0][0]]) q.push(PII(0,0));
	while(!q.empty()){
		PII now = q.front();q.pop();
		int x = now.first, y = now.second;
		char c = g[x][y];
		REP(i,0,4){
			int nx = x + dir[i][0],ny = y + dir[i][1];
			if(nx<0 || nx>=N || ny < 0 || ny >= N || !okc[g[nx][ny]]) continue;
			if(dst[nx][ny] > dst[x][y] + 1){
				dst[nx][ny] = dst[x][y] + 1;
				q.push(PII(nx,ny));
			}
		}
	}
	return dst[N-1][N-1];
}

int main(){
	while(scanf("%d",&N)!=EOF){
		int ans = INF;
		REP(i,0,N) scanf("%s",g[i]);
		REP(m,0,1<<10){
			REP(i,0,10){
				okc['a' + i] = 0;
				okc['A' + i] = 1;
				if((1<<i)&m) swap(okc['a' + i],okc['A'+i]);
			}
			int sol = bfs();
			ans = min(ans,sol);
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;	
}