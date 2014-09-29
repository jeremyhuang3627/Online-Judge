#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

#define M 1000001
#define max(a,b) ((a>b)?a:b)

using namespace std;

int n,a,b;
double t1,t2,k;
vector<pair<double,int> > v;

bool cmp(pair<double,int> p1,pair<double,int> p2)
{
	//return p1.second  p2.second; 
	if(p1.first != p2.first){
		return p1.first > p2.first; 
	}else{
		return p1.second < p2.second;
	} 

}

int main()
{
	cin >> n >> t1 >> t2 >> k;

	for(int i=1;i<=n;i++)
	{
		cin >> a >> b; 
		double time_1 = a*t1*(1-k/100) + b*t2;
		double time_2 = b*t1*(1-k/100) + a*t2;
		//cout << "time_1 " << time_1  << " time_2 " << time_2 << endl;
		v.push_back(make_pair(max(time_1,time_2),i));
	}

	sort(v.begin(),v.end(),cmp);

	for(int i=0;i<v.size();i++)
	{
		printf("%d %.2f\n",v[i].second,v[i].first);
	}

	return 0;
}