#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

#define M 1000000000
#define N 100000

int k,a,n,r=0;

int main()
{
	cin >> n;
	while(n--){
		cin >> k >> a;
		a = ceil(log2(a)/2);
		k += a ? a : 1;
		r = max(k,r);
	}
	cout << r << endl;
}