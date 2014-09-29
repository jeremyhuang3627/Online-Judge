#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

long long n,s;

void p(long long x,int n7,int n4)
{
	if(x>=n && n7==n4 && (x<s || !s)) s = x;
	if(x < n*100){
		p(x*10+4,n7,n4+1);
		p(x*10+7,n7+1,n4);
	}
}

int main()
{
	cin >> n;
	p(0,0,0);
	if(n==0) s = 47;
	cout << s << endl;
	return 0;
}