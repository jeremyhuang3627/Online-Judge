#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n,p,q,cnt=0;

int main()
{
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> p >> q;
		if(q-p >= 2) cnt ++;
	}
	cout << cnt << endl;
	return 0;
}