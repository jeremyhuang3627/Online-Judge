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

void put(vector<int> &v,istringstream &ss){
	while(ss){
		string sub;
		ss >> sub;
		if(sub != "\0"){
			v.push_back(atoi(sub.c_str()));
		}
	}
}

int intpow(int x,int e){
	int ret = 1;
	for(int i=0;i<e;i++)
	{
		ret *= x;
	}
	return ret;
}

int cal(vector<int> &c,int x){
	int val = 0;
	for(int i=c.size()-1;i>=0;i--)
	{
		val += c[c.size()-1 -i]*intpow(x,i);
	}
	return val;
}

int main(){
	int c;
	string l,l2;
	while(getline(cin,l)){
		getline(cin,l2);

		if(l.length() && l2.length()){
			istringstream iss (l);
			istringstream iss2 (l2);
			vector<int> c;
			vector<int> x;
			put(c,iss);
			put(x,iss2);

			for(int i=0;i<x.size();i++){
				int val = cal(c,x[i]);
				cout << val;
				if(i!=x.size()-1){
					cout << " ";
				}
			}
			cout << endl;

		}
	} 
	return 0;
}

