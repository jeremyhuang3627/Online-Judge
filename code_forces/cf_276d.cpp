#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)

using namespace std;

long long l,r,i;

int main(){
	cin >> l >> r;
	for(i=63;i>=0;i--) if((l^r) & (1LL << i)) break;

	cout << (1LL << i + 1) - 1 << endl;
	return 0;
}