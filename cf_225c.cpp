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

int t[M][M][3],rt[M][3],n,m,x,y,cw,cb,ans;
char c[M][M];

/*
int dp(int i,int tl,int c){
	if(i<0 && tl < x){
		return MX;
	}else if(i<0){
		return 0;
	}

	if(!t[i][tl][c]){
		int nc = (c+1)%2;
		t[i][tl][c] = MX;
		if(tl >= x) t[i][tl][c] = min(t[i][tl][c],dp(i-1,1,nc) + rt[i][nc]);
		if(tl <y) t[i][tl][c] = min(t[i][tl][c],dp(i-1,tl+1,c) + rt[i][c]);
	}
	return t[i][tl][c];
} */

int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	memset(rt,0,sizeof(rt));
	F(i,0,n){
		scanf("%s",c[i]);
		F(j,0,m){
			if(c[i][j] =='#') rt[j+1][0]++;
			else if(c[i][j]=='.') rt[j+1][1]++;
		}
	}

	F(j,0,m) t[0][j][0] = t[0][j][1] = (j<x?MX:0);

	F(i,1,m + 1){
		F(j,0,m){
			t[i][j][0] = t[i][j][1] = MX;
			if(j>=x){
				t[i][j][0] = min(t[i][j][0],t[i-1][1][1] + rt[i][1]);
				t[i][j][1] = min(t[i][j][1],t[i-1][1][0] + rt[i][0]);
			}

			if(j<y){
				t[i][j][0] = min(t[i][j][0],t[i-1][j+1][0] + rt[i][0]);
				t[i][j][1] = min(t[i][j][1],t[i-1][j+1][1] + rt[i][1]);
			}
		}
	}

	ans = min(t[m-1][1][0] + rt[m][0],t[m-1][1][1] + rt[m][1]);
	cout << ans << endl;
	return 0;
}