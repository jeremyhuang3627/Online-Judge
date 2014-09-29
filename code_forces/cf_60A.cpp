#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int lm,rm,n,m,e;
string a,b,c,d;
char s[20];

int main()
{
	cin >> n >> m;
	lm = n, rm = 1;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b >> c >> d >> e;
		if(c == "left"){
			lm = min(lm,e - 1);
		}

		if(c == "right"){
			rm = max(rm,e + 1);
		}
	}

	cout << (lm - rm + 1 > 0 ? lm - rm + 1 : -1) << endl;

	return 0;
}