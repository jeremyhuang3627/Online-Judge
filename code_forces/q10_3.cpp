//Third try Virtual Friends
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <tr1/unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)

typedef long long ll;
typedef vector<int> VI;

struct Node{
	string name;
	Node * parent;
	Node(string n):name(n),parent(NULL){}
};

Node * findSet(string n,tr1::unordered_map<string,Node *> &m,tr1::unordered_map<Node *,int> &sz)
{
	if(m[n]->parent != m[n]){
		m[n]->parent = findSet(m[n]->parent->name,m,sz);
	}
	return m[n]->parent;
}

void create_set(string n,tr1::unordered_map<string,Node *> &m,tr1::unordered_map<Node *,int> &sz)
{
	m[n] = new Node(n);
	m[n]->parent = m[n];
	sz[m[n]] = 1;
}

void merge(string n1,string n2,tr1::unordered_map<string,Node *> &m,tr1::unordered_map<Node *,int> &sz)
{
	Node * p1 = findSet(n1,m,sz);
	Node * p2 = findSet(n2,m,sz);

	if(p1==p2){
		return;
	}

	if(sz[p1] >= sz[p2]){
		sz[p1] += sz[p2];
		sz[p2] = 0;
		p2->parent = p1;
	}else{
		sz[p2] += sz[p1];
		sz[p1] = 0;
		p1->parent = p2;
	}
}

int getSize(string n1,tr1::unordered_map<string,Node *> &m, tr1::unordered_map<Node *,int> &sz)
{
	Node * p = findSet(n1,m,sz);
	return sz[p];
}

int main(){
	int cn;
	cin >> cn;
	for(int i=0;i<cn;i++)
	{
		int fn;
		cin >> fn;
		tr1::unordered_map<string,Node *> m;
		tr1::unordered_map<Node *,int> sz;
		for(int j=0;j<fn;j++)
		{
			string n1,n2;
			cin >> n1 >> n2;
			if(!m[n1] && !m[n2]){
				create_set(n1,m,sz);
				create_set(n2,m,sz);
			}else if(!m[n1]){
				create_set(n1,m,sz);
			}else if(!m[n2]){
				create_set(n2,m,sz);
			}
			merge(n1,n2,m,sz);
			int size = getSize(n1,m,sz);
			cout << size << endl;
		}
	}
	return 0;
}