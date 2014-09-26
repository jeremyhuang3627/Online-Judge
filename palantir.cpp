#include <iostream>
using namespace std;

#define W 1001
#define H 1001

int M,N,E,g[W][H],dp[W][H],x,y,curT=0,minT;

void dfs(int x,int y){
	//cout << "x " << x << " y " << y << " cur " << curT << endl;
	if(x==M-1 && y == N-1){
		minT = min(minT,curT + g[x][y]);
		return;
	}

	if(x>M-1 || y >N-1)return;

	curT += g[x][y];
	dfs(x+1,y);
	dfs(x,y+1);
	curT -= g[x][y];
	return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	cin >> M >> N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >>g[i][j];
		}
	}
	cin >> E;
	for(int i=0;i<E;i++){
		cin >> x >> y;
		minT = 1E9;
		dfs(x,y);
		cout << minT << endl;
	}
    return 0;
}