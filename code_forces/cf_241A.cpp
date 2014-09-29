#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

#define M 1005

int m,k,d[M],s[M],i,ts=0,ms,t=0;

int main()
{
	cin >> m >> k;

	for(i=0;i<m;i++)
	{
		cin >> d[i];
	}

	for(i=0;i<m;i++)
	{
		cin >> s[i];
	}

	ms=s[0];

	for(i=0;i<m;i++)
	{
		ts+=s[i];
		
		if(s[i] > ms){
			ms = s[i];
		}

		while(ts<d[i]){
			ts += ms;
			t+=k;
		}
		t+=d[i];
		ts-=d[i];
	}

	cout << t << endl;
	return 0;
}