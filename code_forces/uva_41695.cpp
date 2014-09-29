#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int a,b,n,m;

void topo(int num,vector<int> &ans,vector<int> adj[],vector<bool> &v)
{	
	for(int i=0;i<adj[num].size();i++){
		if(!v[adj[num][i]]){
			topo(adj[num][i],ans,adj,v);
		}
	}
	v[num] = true;
	ans.push_back(num);
}

int main()
{	
	cin >> n >> m;
	while(n!=0 || m!=0){
		vector<int> adj[105];
		vector<bool> v (105);

		for(int i=0;i<m;i++){
			cin >> a >> b;
			adj[b].push_back(a);
		}

		vector<int> ans;
		for(int i=1;i<=n;i++){
			if(!v[i])
			{
				topo(i,ans,adj,v);
			}
		}
		
		for(int i=0;i<ans.size();i++){
			cout << ans[i] << " ";
		}
		cout << endl;
		cin >> n >> m;
	}

	return 0;
}