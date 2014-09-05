#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define M 50

int n,m,x,y,i;

vector<int> a[M];
bool visited[M];
vector<int> v;
vector<vector<vector<int> > > vv (5);

void dfs(int i)
{
	visited[i] = true;
	v.push_back(i);

	for(int j=0;j<a[i].size();j++){
		if(!visited[a[i][j]])
		{
			dfs(a[i][j]);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);

	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}

	for(int i=1;i<=n;i++)
	{	
		v.clear();

		if(!visited[i]){
			dfs(i);
		}

		if(v.size() > 3){
			cout << "-1" <<endl;
			return 0;
		}

		vv[v.size()].push_back(v);
	}

	if(vv[1].size() < vv[2].size() || (vv[1].size() - vv[2].size()) % 3 != 0) {
		cout << "-1" << endl;
	}else{

		for(i=0;i<vv[2].size();i++)
		{
			printf("%d %d %d\n", vv[1][i][0],vv[2][i][0],vv[2][i][1]);
		}

		for(;i<vv[1].size();i+=3){
			printf("%d %d %d\n",vv[1][i][0],vv[1][i+1][0],vv[1][i+2][0]);
		}

		for(i=0;i<vv[3].size();i++)
		{
			printf("%d %d %d\n", vv[3][i][0],vv[3][i][1],vv[3][i][2]);
		}
	}

	return 0;
}