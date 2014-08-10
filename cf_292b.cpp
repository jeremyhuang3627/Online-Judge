#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define max(a,b) (a > b ? a : b)

using namespace std;

//int a [100000 + 100];

int main(){
	int n,m;
	//memset(a,0,sizeof(a));
	scanf("%d %d",&n,&m);

	map<int,vector<int> > g; 

	int node_1,node_2;
	F(i,0,m){
		scanf("%d %d",&node_1,&node_2);
		g[node_1].push_back(node_2);
		g[node_2].push_back(node_1);
		//cout << "pushing " << node_2 << " to " << node_1 << endl;
	}

	bool isBus= true, isRing = true, isStar = true;

	if(n == m + 1 ){
		isRing = false;
		// check for isBus

		int i = 1;

		vector<int> nodes;
		F(i,1,n + 1) if(g[i].size() == 1 ) nodes.push_back(i);

		if(nodes.size() != 2){
			isBus = false;
			//cout << "node size is not 2 " << nodes.size() << endl;
		}else{
			int node = nodes[0];
			map<int,bool> visited;
			while(node != nodes[1]){
				visited[node] = true;
				if(g[node].size() != 2 && node != nodes[0]){
					isBus = false;
					cout << "node size is 1 " << g[node].size() << " for node " << node << endl;
					break;
				}

			}
		}

		// check for isStar 

		int maxEdgeNum = 0;
		F(i,1,n + 1) maxEdgeNum = max(maxEdgeNum, g[i].size());
		if(maxEdgeNum != m) isStar = false;
		
	}else if(n == m){
		// check for isRing
		isStar = false;
		isBus = false;

		int node_cnt = 0;
		int i = 1;

		map<int,bool> visited;

		while(node_cnt <= n){

			if(g[i].size() != 1){
				isRing = false;
				break;
			}

			visited[i] = true;
			node_cnt ++;
			i = g[i][0];
		}	

		F(i,1,n + 1){
			if(!visited[i]){
				isRing = false;
			}
		}
	}else{
		isBus = isRing = isStar = false;
	}

	if(!isBus && !isRing && !isStar) cout << "unknown topology" << endl;
	if(isBus) cout << "bus topology" << endl;
	if(isStar) cout << "star topology" << endl;
	if(isRing) cout << "ring topology" << endl;

	return 0;
}