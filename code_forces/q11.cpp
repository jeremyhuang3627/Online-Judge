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

vector<bool> intToBitset(int i,int d)
{
	vector<bool> ret (d,false);
	for(int j=d-1;j>=0;j--){
		if(i&1){
			ret[j] = true;
		}
		i >>= 1;
	}
	return ret;
}

int bitsetToInt(vector<bool> s){
	int n = 0;
	for(int i=0;i<s.size();i++)
	{	
		n <<= 1;
		if(s[i]){
			n+=1;
		}
	}
	return n;
}

vector<int> getNeighbors(int i,int d)
{
	vector<bool> s = intToBitset(i,d);
	vector<int> ret;
	for(int j=0;j<s.size();j++)
	{
		s[j] = s[j] ? false : true;
		int n = bitsetToInt(s);
		ret.push_back(n);
		s[j] = s[j] ? false : true;
	}
	return ret;
}

int main(){
	int d;
	int numCorners;
	while(true){
		cin >> d;
		if(cin.eof()){
			break;
		}

		numCorners = (int)pow(2.0,(double)d);
		vector<int> ws;
		vector<int> sums;
		for(int i=0;i<numCorners;i++)
		{
			int w;
			cin >> w;
			ws.push_back(w);
		}

		
		sums.resize(ws.size());

		for(int i=0;i<ws.size();i++)
		{
			vector<int> ns = getNeighbors(i,d);
			int po = 0;
			for(int j=0;j<ns.size();j++)
			{
				po += ws[ns[j]]; 
			}
			sums[i] = po;
		}

		int maxPoSum = 0;

		for(int i=0;i<ws.size();i++)
		{
			vector<int> ns = getNeighbors(i,d);
			for(int j=0;j<ns.size();j++)
			{
				maxPoSum = max(maxPoSum,sums[ns[j]] + sums[i]);
			}
		}
		cout << maxPoSum << endl;
	}

	return 0;
}