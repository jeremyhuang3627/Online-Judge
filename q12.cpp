//The Most Potent Corner
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
#include <bitset> 

using namespace std;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin(); i!=(v).end(); i++)

typedef long long ll;
typedef vector<int> VI;

struct Node{
	int val;
	int smallerNum;//number of nodes smaller
	Node * left;
	Node * right;
	Node(int x):val(x),smallerNum(0),left(NULL),right(NULL){}
};

Node * insert(Node * &r, Node * n)
{
	if(n==NULL){
		return n;
	}

	if(r==NULL){
		r = n;
		return r;
	}

	if(n->val <= r->val){
		r->smallerNum ++;
		return insert(r->left,n);
	}else{
		n->smallerNum ++;
		return insert(r->right,n);
	}
}

int main(){
	int c;
	cin >> c;
	for(int i=0;i<c;i++)
	{
		int N;
		cin >> N;
		vector<int> ps;

		for(int j=0;j<N;j++)
		{
			int n;
			cin >> n;
			ps.push_back(n);
		}

		//from left to right
		vector<int> numWeakerLR;
		numWeakerLR.resize(ps.size()); 
		Node * rootLR = NULL;

		//from right to left
		vector<int> numWeakerRL;
		numWeakerRL.resize(ps.size());
		Node * rootRL = NULL;

		for(int j=0;j<ps.size();j++){
			Node * nLR = insert(rootLR,new Node(ps[j]));
			int numSmaller = nLR->smallerNum;
			numWeakerLR[j] = numSmaller;

			Node * nRL = insert(rootRL,new Node(ps[ps.size()-1-j]));
			numSmaller = nRL->smallerNum;
			numWeakerRL[ps.size()-1-j] = numSmaller;
		}

		unsigned long long numGames = 0;
		for(int j=0;j<ps.size();j++){
			numGames += numWeakerLR[j] * (ps.size()-j-1 - numWeakerRL[j]);
			numGames += (j-numWeakerLR[j]) * numWeakerRL[j];
		}

		cout << numGames << endl;
	}
	return 0;
}