#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> searchRange(int a[],int n,int target)
{
	int s,e,lo=0,hi=n-1,f=0,mid;
	vector<int> ret;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		if(target > a[mid]){
			lo = mid + 1;
		}else
		{
			hi = mid - 1;
		}
	}

	if(a[lo] != target){
		ret.push_back(-1);
		ret.push_back(-1);
		return ret;
	}

	ret.push_back(lo);

	lo = 0,hi=n-1;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(target >= a[mid])
		{
			lo = mid + 1;
		}else{
			hi = mid - 1;
		}
	}

	ret.push_back(lo-1);
	return ret;
}

int main()
{
	int n = 2;
	int a[3] = {1,2,3};
	vector<int> v = searchRange(a,3,2);
	cout << v[0] << " " << v[1] << endl;

	return 0;
}