#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int bin_search(vector<int> &A,int val)
{
	int lo = 0,hi=A.size()-1; 
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(A[mid] <= val) lo = mid + 1;
		else hi = mid - 1;
	}
	return lo;
}

int solution(vector<int> &A){
    // write your code in C++11
	int mx = A[max_element(A.begin(),A.end()) - A.begin()];
	int mm = A[min_element(A.begin(),A.end()) - A.begin()];
	int mg = 0;
	sort(A.begin(),A.end());
	//cout << "A[mm] " << A[mm] << "A[mx] " << A[mx] << endl;

	for(int i=mm;i<=mx;i++){
		int g=1E9;
		int pos = bin_search(A,i);
		//cout << "pos " << pos << " i "  << i << endl;
		mg = max(mg, min(abs(i-A[pos-1]),abs(i-A[pos])) );
	}
	return mg;
}

int main()
{
	int a[8] = {10,0,8,2,-1,12,11,3};
	vector<int> v (a,a+8);
	cout << solution(v) << endl;
	return 0;
}