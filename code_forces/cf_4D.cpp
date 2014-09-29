#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

int n,cw,ch,cur;
int w [5005];
int h [5005];
int d [5005];
int p [5005];

int dp(int v){
	if(d[v]){
		return d[v];
	}

	F(i,1,n + 1){
		if(w[i] > w[v] && h[i] > h[v]){
			if(dp(i) + 1 > d[v]){
				d[v] = dp(i) + 1;
				p[v] = i;
			}
		}
	}
	return d[v];
}

int main(){
	fill_n(d,5005,0);
	scanf("%d%d%d",&n,&w[0],&h[0]);
	F(i,1,n + 1){
		scanf("%d%d",&w[i],&h[i]);
	}
	dp(0);
	cout << d[0] << endl;
	int cur = p[0];
	while(cur!=0){
		cout << cur << " ";
		cur = p[cur];
	}
	cout << endl;
	return 0;
}