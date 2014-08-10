//Open Source
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

struct cmp{
	bool operator()(pair<string,int> p1,pair<string,int> p2)
	{
		if(p1.second == p2.second){
			return p1.first < p2.first;
		}else{
			return p1.second > p2.second;
		}
	}
};

bool allUpper(string s){
	for(int i=0;i<s.length();i++)
	{
		if(isalpha(s[i]) && !isupper(s[i])){
			return false;
		}
	}
	return true;
}

int main(){
	string l;
	while(getline(cin,l)){
		if(l.length() == 1 && l[0] == '0'){
			break;
		}

		vector<pair<string,int> > summary;
		vector<string> list;
		int cnt = 0;
		string prg = l;
		list.push_back(prg);
		string n;
		set<string> s;
		
		while(true){
			getline(cin,n);
			if(n.length() == 1 && n[0] =='1')
			{	
				for(set<string>::iterator it=s.begin();it != s.end();it++)
				{
					list.push_back(*it);
				}
				break;
			}
			if(!allUpper(n)){
				s.insert(n);
			}else{
				for(set<string>::iterator it=s.begin();it != s.end();it++)
				{
					list.push_back(*it);
				}
				s.clear();
				list.push_back(n);
			}
		}

		map<string,int> m;
		for(int i=0;i<list.size();i++)
		{
			m[list[i]]++;
		}

		prg = list[0];
		s.clear();
		for(int i=1;i<list.size();i++){
			if(allUpper(list[i])){
				summary.push_back(make_pair(prg,s.size()));
				prg = list[i];
				s.clear();
			}else if(m[list[i]]==1){
				s.insert(list[i]);
			}
		}

		summary.push_back(make_pair(prg,s.size()));

		sort(summary.begin(),summary.end(),cmp());

		for(int i=0;i<summary.size();i++)
		{
			cout << summary[i].first << " " << summary[i].second << endl;
		}
	}
	return 0;
}