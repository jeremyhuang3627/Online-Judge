#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define mod 100000000

using namespace std;

struct Node{
	int label;
	int redCnt;
	int pathLen;
	vector<Node *> neighbors;
};

map<int,Node *> m;
map<pair<Node *,Node *> ,bool> direction;
map<Node *,bool> visited;
int n,c1,c2,minInv,totalRedCnt;
vector<int> capitals;

Node * makeNode(int x){
	Node * n = new Node();
	n->label = x;
	n->redCnt = 0;
	n->pathLen = 0;
	n->neighbors.clear();
	return n;
}

int dfs(Node * n,int depth,int redCnt){
	n->pathLen = depth;
	n->redCnt = redCnt;

	//cout << "depth " << depth << " node " << n->label << " has redCnt " << n->redCnt << " pathLen " << n->pathLen << endl;
	int totalRed =  0;

	F(i,0,n->neighbors.size()){
		Node * nbr = n->neighbors[i];
		if(!visited[nbr]){
			visited[nbr] = true;
			if(direction[make_pair(n,nbr)]){
				totalRed += dfs(nbr,depth+1,redCnt) ;
			}else{
				totalRed += dfs(nbr,depth+1,redCnt+1) + 1;
			}
			visited[nbr] = false;
		}
	}

	return totalRed;
}

void findMin(Node * n){
	if(n==NULL){
		return;
	}

	int numInv = totalRedCnt + n->pathLen - 2 * n->redCnt; 
	if(numInv < minInv){
		capitals.clear();
		capitals.push_back(n->label);
		minInv = numInv;
	}else if(numInv == minInv){
		capitals.push_back(n->label);
	}

	F(i,0,n->neighbors.size()){
		Node * nbr = n->neighbors[i];
		if(!visited[nbr]){
			visited[nbr] = true;
			findMin(nbr);
			visited[nbr] = false;
		}
	}
}

int main(){
	scanf("%d",&n);
	while(scanf("%d%d",&c1,&c2) != EOF){
		if(!m[c1]){
			m[c1] = makeNode(c1);
		}
		if(!m[c2]){
			m[c2] = makeNode(c2);
		}
		m[c1]->neighbors.push_back(m[c2]);
		m[c2]->neighbors.push_back(m[c1]);
		direction[make_pair(m[c1],m[c2])] = true;
	}

	visited[m[1]] = true;
	totalRedCnt = dfs(m[1],0,0);
	minInv = 1e9;
	findMin(m[1]);

	cout << minInv << endl;
	sort(capitals.begin(),capitals.end());
	F(i,0,capitals.size()){
		cout << capitals[i] << " ";
	}
	cout << endl;
	
	return 0;
}