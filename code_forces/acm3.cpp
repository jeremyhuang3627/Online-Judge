#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int T,val,c=1;
string s;
vector<pair<int,string> > v;
vector<string> sv;

int main()
{
	cin >> T;
	while(T--){
		cout << "Case #"<< c<< ":" << endl;
		v.clear();
		sv.clear();
		for(int i=0;i<10;i++){
			cin >> s >> val;
			v.push_back(make_pair(val,s));	
			sv.push_back(s);
		}
		sort(v.begin(),v.end());
		int i = v.size()-1;
		int m = v[i].first;
		map<string,bool> mm;
		while(v[i].first==m){
			mm[v[i].second] = true;
		// 	t.push_back(v[i].second);	
			i--;
		}
		for(int i=0;i<sv.size();i++)
		{
			if(mm[sv[i]]) cout << sv[i] << endl;
		}
		c++;
	}	
	return 0;
}