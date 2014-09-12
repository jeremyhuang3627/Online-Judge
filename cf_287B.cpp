#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long n,k,l,lo,hi,mid,s, ans;

int main()
{
	cin >> n >> k;
	l = (2+k)*(k-1)/2 - (k-2);
	if(n > l){
		cout << "-1" << endl;
		return 0;
	}

	lo = 1,hi = k-1;

	while(lo < hi)
	{	
		mid = (lo + hi)/2;
		s = (mid-1)*k - mid*(mid-1)/2 + 2;

		if(n > s){
			lo = mid + 1;
		}else if(n < s){
			hi = mid - 1;
		}else{
			lo = mid;
			break;
		}
	}

	if(n < (lo-1)*k - lo*(lo-1)/2 + 2 )
	{
		lo --;
	}

	cout << lo << endl;
	return 0;
}