#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define M 100005

long long n,d,a,b,x[M],y[M],sum=0,i;
vector<pair<long long,long long> > v;

int main()
{
	cin >> n >> d >> a >> b;

	for(i=0;i<n;i++)
	{
		cin >> x[i] >> y[i];
		int total = x[i]*a + y[i]*b;
		v.push_back(make_pair(total,i));
	}

	sort(v.begin(),v.end());

	for(i=0;i<n;i++)
	{
		sum += v[i].first;
		if(sum > d){
			break;
		}
	}		

	cout << i << endl;

	for(int j=0;j<i;j++)
	{
		cout << v[j].second + 1 << " ";
	}
	return 0;
}