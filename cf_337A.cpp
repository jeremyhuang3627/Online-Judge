#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define min(a, b)  (a > b ? b : a)
#define M 55

int a[M],n,m,mm = 1E9;

using namespace std;

int main(){
	cin >> n >> m;	
	F(i,0,m){
		cin >> a[i];
	}
	sort(a,a+m);

	F(i,0,m-n+1){
		mm = min(mm,a[i+n-1] - a[i]);
	}

	cout << mm << endl;
	return 0;
}