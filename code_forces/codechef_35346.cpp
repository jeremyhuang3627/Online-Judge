#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <cassert>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define M 100005

int n,m,a[M],sum=0,s[M],l,r;

int getSum(int num,int l,int r){
	int lo = l,hi = r;
	while(lo <= hi){
		int m = (lo + hi)/2;
		if(a[m] > num){
			hi = m - 1;
		}else if(a[m] < num){
			lo = m + 1;
		}else{
			return s[m+1]-s[l];
		}
	}
	return s[lo]-s[l];
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);

	for(int i=1;i<=n;i++){
		s[i] = sum;
		sum += a[i];
	}

	cin >> m;
	for(int i=0;i<m;i++){
		cin >> l >> r;
		int S = 0;
		while(true){
			int nS = getSum(S+1,l,r);
			if(S == nS){
				break;
			}
			S = nS;
		}
		cout << S + 1 << endl;
	}

	return 0; 
}