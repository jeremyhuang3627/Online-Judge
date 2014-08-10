#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

vector<pair<int,int> > v;
int p,q,n;

int main()
{	
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> p >> q;
		v.push_back(make_pair(p,q));
	}

	sort(v.begin(),v.end());

	for(int i=0;i<n-1;i++){
		if(v[i].second >= v[i+1].second){
			cout << "Happy Alex" << endl;
			return 0;
		}
	}
	cout << "Poor Alex" << endl;
	return 0;
}