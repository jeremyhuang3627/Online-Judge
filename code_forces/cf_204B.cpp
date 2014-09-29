#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

#define M 100000005
#define N 100005

int n,f,b,mm=N;

map<int,pair<int,int> > m;

int main()
{
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> f >> b;
		m[f].first++;
		m[f].second++;
		if(f!=b){			
			m[b].second++;
		}
	}

	map<int,pair<int,int> >::iterator it;
	for(it=m.begin();it!=m.end();it++){
		//cout << it->first << " it->second.first " << it->second.first << " it->second.second "<< it->second.second << endl;
		if(it->second.second >= (n+1)/2 && (n+1)/2 - it->second.first < mm){
			mm = (n+1)/2 - it->second.first;
			//cout << "it->second.first " << it->second.first << endl;
		}
	}

	cout << (mm==N ? -1 : mm < 0 ? 0 : mm) << endl;
	return 0;
}