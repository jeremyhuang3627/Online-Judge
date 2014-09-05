#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define M 1005

int r,c,er=-1,ec=-1,ans=0,sl=1E9;
char g[M][M];
bool visited[M][M];
map<pair<int,int>,int> m;

int main()
{
	scanf("%d%d",&r,&c);
	for(int i=0;i<r;i++){
		scanf("%s",g[i]);
		for(int j=0;j<c;j++)
		{
			if(g[i][j]=='E') er=i,ec=j;
		}
	}

	//bfs
	memset(visited,0,sizeof(visited));
	queue<pair<int,int> > q;
	visited[er][ec] = true;
	q.push(make_pair(er,ec));
	m[make_pair(er,ec)] = 0;

	while(!q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();
		int l = m[p];

		if(l>sl){
			break;
		}
		for(int i=-1;i<=1;i++)
		{
			if(i!=0)
			{	
				if(p.first+i < r && p.first+i >=0  && !visited[p.first + i][p.second] && (isdigit(g[p.first + i][p.second])|| g[p.first + i][p.second]=='S') ){
					if(g[p.first + i][p.second]=='S'){
						sl = l;
					}else{
					ans += g[p.first + i][p.second] - '0';
					q.push(make_pair(p.first + i,p.second));
					visited[p.first + i][p.second] = true;
					m[make_pair(p.first + i,p.second)] = l + 1;
					}
				}

				if(p.second+i < c && p.second+i >=0  && !visited[p.first][p.second + i] && (isdigit(g[p.first][p.second + i]) || g[p.first][p.second + i] == 'S') ){
					if(g[p.first][p.second + i]=='S'){
						sl = l;
					}else{
					ans += g[p.first][p.second + i] - '0';
					q.push(make_pair(p.first,p.second + i));
					visited[p.first][p.second + i] = true;
					m[make_pair(p.first,p.second + i)] = l + 1;
					}
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}