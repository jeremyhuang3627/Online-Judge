#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 505
#define INF 1E9

using namespace std;

int adj[M][M],n,p[M][M],o[M],r[M];
long long sum[M];

int main(){
	scanf("%d",&n);
	
	F(i,1,n +1){
		F(j,1,n +1){
			scanf("%d",&adj[i][j]);
			p[i][j] = adj[i][j];
		}
	}

	F(i,1,n + 1){
		scanf("%d",&o[i]);
	}

	for(int k=n;k>=1;k--){
		r[o[k]] = 1;
		for(int i=1;i<n+1;i++){
			for(int j=1;j<n+1;j++){
				p[i][j] = min(p[i][j],p[i][o[k]] + p[o[k]][j]);
				if(r[i] && r[j]){
					sum[k] += p[i][j];
				}
			}
		}
	}

	F(i,1,n + 1){
		cout << sum[i]<< " ";
	}

	cout << endl;
	return 0;
}