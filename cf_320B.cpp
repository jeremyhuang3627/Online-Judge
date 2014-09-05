#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define M 105;

int n,i,t,a[M],b[M],visited[M],r=0,x,y;

void dfs(int m){
	visited[m] = 1;
	for(int i=0;i<n;i++){

		if(visited[i]) continue;

		if(a[m] > a[i] && a[m] < b[i]){
			dfs(i);
		}

		if(b[m] > a[i] && b[m] < b[i])
		{
			dfs(i);
		}
	}
}

int main()
{	
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> t >> x >> y;
		if(t==1){
			r++;a[r] = x;b[r] = y;
		}else if(t == 2)
		{	
			fill_n(visited,105,0);
			dfs(x);
			visited[y] ? printf("YES\n") : printf("NO\n");
		}
	}

	return 0;
}