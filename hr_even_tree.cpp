#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MX 101

int M,N,x,y;
vector<int> l[MX];
bool visited[MX];
int cnt[MX];

int dfs(int n,int p)
{
//	cout << "n " << n << " p " << p << endl;
	int tt = 1;
	for(int i=0;i<l[n].size();i++)
	{
		if(l[n][i]!=p){
			tt += dfs(l[n][i],n);
		}
	}
	cnt[n] = tt;
//	cout << "n " << n << " tt " << tt << endl;
	return tt;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
	cin >> M >> N;
	for(int i=0;i<N;i++)
	{
		cin >> x >> y;
		l[x].push_back(y);
		l[y].push_back(x);
	}
	dfs(1,0);
	int ans = 0;
	for(int i=0;i<M;i++){
	//	cout << cnt[i+1] << " ";
		if(cnt[i+1]%2==0){
			ans++;
		}
	}
//	cout << endl;
	cout << ans-1 << endl;
    return 0;
}
