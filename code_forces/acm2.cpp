#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int n,a[202],i=0,cnt[202],x,p,q;

int main()
{
	cin >> n;
	cin >> p;
	for(int i=0;i<p;i++){
		cin >> x;
		cnt[x] = 1;
	}

	cin >> q;
	for(int i=0;i<q;i++){
		cin >> x;
		cnt[x] = 1;
	}

	bool ok = true;
	for(int i=1;i<=n;i++){
		if(!cnt[i]) ok = false;
	}
	cout << (ok ? "I become the guy." : "Oh, my keyboard!") << endl;
	return 0;
}