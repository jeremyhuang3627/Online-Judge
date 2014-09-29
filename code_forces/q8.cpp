//Maximum Sub-sequence Product
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

ll getMaxNum(vector<ll> v)
{
	ll retMax = -999999;
	for(int l=1;l<=v.size();l++)
	{
		ll sum = 1;
		for(int i=0;i<=v.size()-l;i++)
		{
			if(i != 0){
				if(v[i-1]){
					sum /= v[i-1];
				}
				sum *= v[i+l-1];
			}else{
				for(int j=i;j<i+l;j++)
				{
					sum *= v[j];
				}
			}
			retMax = max(retMax,sum);
		}
	}
	return retMax;
}

int main(){
	while(true){
		if(cin.eof()){
			break;
		}

		vector<ll> v;
		ll num;
		cin >> num;
		while(num != -999999){
			v.push_back(num);
			cin >> num;
		}

		int maxNum = getMaxNum(v);

		if(maxNum != -999999){
			cout << maxNum << endl;
		}
	}
	return 0;
}