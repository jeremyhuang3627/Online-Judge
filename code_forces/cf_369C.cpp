#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

#define M 100005

vector<int> a[M];
map<pair<int,int>,int> m;
vector<int> ret;
int n,x,y,t;

int dfs(int n,int p){
	int sk = 0;
	for(int i=0;i<a[n].size();i++){
		if(a[n][i] != p){
			int k = dfs(a[n][i],n);
			sk += ((k) ? k : (m[make_pair(n,a[n][i])] == 2)); 
			if(!k && m[make_pair(n,a[n][i])] == 2){
				ret.push_back(a[n][i]);
			}
		}
	}
	return sk;	
}

int main()
{
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> x >> y >> t;
		m[make_pair(x,y)] = t;
		m[make_pair(y,x)] = t;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	int ans = dfs(1,0);
	cout << ans << endl;
	for(int i=0;i<ret.size();i++){
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}