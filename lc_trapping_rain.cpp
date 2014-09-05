#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <queue>

using namespace std;

int trap(int A[], int n) {
	int lr [n];
	int rl [n];

	int m=A[0],midx = 0;

	for(int i=0;i<n;i++){
		if(A[i] > m){
			m = A[i];
			midx = i;
		}
		lr[i] = midx;
	}

	m = A[n-1],midx = n-1;

	for(int i=n-1;i>=0;i--)
	{
		if(A[i] > m){
			m = A[i];
			midx = i;
		}
		rl[i] = midx;
	}

	int ans = 0;
	for(int i=0;i<n;i++){
		ans += (min(A[lr[i]],A[rl[i]]) - A[i]);
	}
	return ans;
}

int main()
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int ans = trap(a,12);
	cout << ans << endl;
	return 0;
}