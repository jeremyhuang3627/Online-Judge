#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)

typedef long long ll;
typedef vector<int> VI;

map<string,bool> visited;
map<string,int> mcnt;

int getNumFnds(map<string,vector<string> > &m,string s){
	int n = 0;
	visited[s] = true;

	for(int i=0;i<m[s].size();i++)
	{	
		if(!visited[m[s][i]]){
			n += getNumFnds(m,m[s][i]) + 1;
		}
	}

	return n;
}

int main(){
	int cn;
	cin >> cn;
	for(int i=0;i<cn;i++)
	{
		int fn;
		cin >> fn;
		map<string,vector<string> > m;
		for(int j=0;j<fn;j++)
		{
			string n1,n2; 
			cin >> n1 >> n2;
			visited.clear();
			int nf1 = getNumFnds(m,n1) + 1;
			int nf2 = 0;
			if(!visited[n2]){
			   nf2 = getNumFnds(m,n2) + 1;
			}
			m[n1].push_back(n2);
			m[n2].push_back(n1);
			int total = nf1 + nf2;
			cout << total << " ";
		}
	}
	return 0;
}